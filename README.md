# KYC Verification Microservice — Architecture Summary

## 1. Goals

- One generic contract between backend and KYC microservice, regardless of verification type (PAN, Aadhaar, Bank, future types) or which provider handles it.
- Adding a new provider — even one with a new step count — should require **no changes to the backend or frontend**, and minimal, isolated changes inside the microservice.
- Clear, non-overlapping responsibilities for **retry** (heal a failure within one provider attempt) vs **fallback** (choose a provider for a new attempt).

---

## 2. Layered architecture

```
Frontend → Backend (/aadhaar, /pan, /bank ...) → KYC Microservice → Provider adapters (A, B, C, ...)
```

- **Frontend**: calls one stable endpoint per verification type. Has no knowledge of providers, steps, or retries.
- **Backend**: picks *which flow/verification type* to use for the user (business rule), forwards to the microservice, persists only the final verdict. Holds no verification state.
- **KYC microservice**: owns everything else — provider selection, attempt state, retries, circuit breakers, step sequencing. This is the only layer that changes when a provider is added or changed.
- **Provider adapters**: one per (flow shape × vendor), composed with vendor-specific clients.

---

## 3. Generic API contract (backend ↔ microservice)

Three endpoints only, for any verification type:

- `POST /verify/{type}/initiate`
- `GET /verify/{attempt_id}/status`
- `POST /verify/{attempt_id}/callback` (webview redirect / OTP submit)

Response is always one of four normalized states:

| State | Meaning |
|---|---|
| `ACTION_REQUIRED` | User must do something next (`type: WEBVIEW` or `OTP`, plus payload) |
| `PENDING` | Processing internally; backend should poll |
| `SUCCESS` | Verified; data returned |
| `FAILED` | Attempt exhausted; user must explicitly retry |

A PAN 1-call flow and an Aadhaar 3-call flow both collapse into this same shape from the backend's point of view.

---

## 4. Class design (flat hierarchy)

```
VerificationAdapter (abstract base)
 ├── PanAdapter          (1 step)
 ├── WebviewSaveAdapter  (2 steps — used by Aadhaar A, B)
 └── OtpAdapter          (3 steps — used by Aadhaar C)
```

- All adapters extend `VerificationAdapter` directly — no intermediate flow-shape layer.
- Shared, non-overridden base methods: `validateTransition()`, `executeStep()` (drives retry policy), step persistence.
- Each adapter declares only: `getSteps()`, `initiate()`, `handleStep()`.

### Composition, not inheritance, for vendor specifics

```
interface ProviderClient { /* vendor-specific raw API calls */ }

class OtpAdapter extends VerificationAdapter {
  constructor(private client: OtpProviderClient, private config: AdapterConfig) {}
}

class ProviderCClient implements OtpProviderClient { ... }
```

**Rule of thumb:**
- New vendor, same flow shape → write a new `ProviderClient` only. Adapter class unchanged.
- New flow shape entirely → new `VerificationAdapter` subclass.

This is what keeps onboarding a provider cheap: it's a new client class plus a config entry, never a change to shared logic.

---

## 5. Retry policy & circuit breaker — composed strategy objects

Not inherited behavior, not hardcoded per class — injected objects, configured per **step**:

```
interface RetryPolicy {
  shouldRetry(attemptNumber: number, error: Error): boolean
  nextDelay(attemptNumber: number): number
}
```

Example config for the OTP adapter:

```
sendOtp: NoRetryPolicy()                    // retrying re-sends OTP to user's phone
verifyOtp: ExponentialBackoff(2, 500ms)
save:      ExponentialBackoff(5, 1000ms)    // idempotent, cheap — retry generously
```

`CircuitBreaker` follows the same pattern — one instance per (provider, call type), injected. Breaker weighting:
- `initiate()` failures → high weight (real health signal)
- mid-flow / `save()` failures → low weight or excluded (often user-side, not provider health)

Changing retry counts or breaker thresholds is a config change, never a code change.

---

## 6. Provider registry & selection

- `ProviderRegistry`: maps `(verificationType, providerId) → adapter instance`, built from config at startup.
- Orchestrator asks the registry for the next eligible provider; registry filters out providers with an open breaker.
- Priority order, retry counts, and breaker thresholds are **config-driven**, not hardcoded — reorderable without a deploy.

---

## 7. Attempt state machine

```
INITIATED → AWAITING_ACTION → PROCESSING → SUCCESS
                                        ↘ FAILED / EXPIRED
```

Attempt record (owned entirely by the microservice):

`id, user_id, verification_type, provider_id, current_step, status, retry_count_per_step, transaction_ref, idempotency_key, created_at, expires_at, failure_reason`

- TTL per step; background sweep marks stale `AWAITING_ACTION` attempts `EXPIRED`.
- All transitions validated — invalid transitions rejected defensively.

---

## 8. Retry vs. fallback — decision rule

> **Retry** heals a failure *within* an attempt, same provider.
> **Fallback** only ever selects the provider for a *new* attempt.

- Transient failure at any step → retry same provider/step with backoff.
- `initiate()` fails after retries exhausted / breaker open → fallback to next provider immediately (user hasn't invested anything yet).
- Mid-flow failure after user already acted → mark `FAILED`, surface explicit retry to user. 1st failure → retry same provider. 2nd+ failure for this user → escalate to next provider.
- Hard cap on total attempts per user per verification (e.g. 3) → route to manual review after that.

---

## 9. Edge cases and handling

| Edge case | Handling |
|---|---|
| Duplicate/concurrent submission | Distributed lock per `(user_id, verification_type)`; return existing in-flight attempt |
| Ambiguous failure on cost-incurring call (e.g. `sendOtp` timeout) | Never auto-retry; idempotency key if provider supports it; otherwise require explicit user retry |
| Webview/OTP session expiry | Per-step TTL + background expiry sweep |
| Late or duplicate callback | Idempotent handler (no-op if attempt already terminal); verify webhook signature |
| Verified but save failed after retries | Push to dead-letter/reconciliation queue — never make user redo OTP/webview |
| All providers exhausted | Route to `PENDING_MANUAL_REVIEW`, alert ops, don't hard-fail the user |
| Breaker flapping | Minimum time-in-open before probing; require N consecutive successes to fully close |
| Rate limits | Separate token-bucket limiter per provider — distinct from circuit breaker (quota vs. health) |
| PII / compliance | Mask Aadhaar/OTP in logs; encrypt attempt records at rest; separate immutable audit/consent log with its own retention policy |
| Provider schema drift | Contract tests per `ProviderClient` against recorded vendor fixtures, run in CI |

---

## 10. Observability

Emit structured events per state transition: `attempt_id, provider_id, step, status, latency`. Enables dashboards for: success rate per provider per step, breaker trip frequency, average completion time, abandonment rate.

---

## 11. Best-practice checklist

- [ ] Flat adapter hierarchy — one level under `VerificationAdapter`
- [ ] Vendor specifics only in `ProviderClient` implementations, injected
- [ ] Retry policy and circuit breaker as per-step injected objects, config-driven
- [ ] Idempotency key on every retryable / side-effecting call
- [ ] Audit/consent log kept separate from operational attempt state
- [ ] Backend and frontend hold zero verification-flow state
- [ ] Contract tests per provider client in CI
- [ ] New provider onboarding = new client class + config entry only
