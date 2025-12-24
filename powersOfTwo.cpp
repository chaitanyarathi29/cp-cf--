#include <iostream>
#include <vector> 
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    int ones = __builtin_popcountll(n);

    if (k < ones || k > n) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    vector<long long> v;
    for (int i = 0; i < 63; i++) {
        if (n & (1LL << i)) {
            v.push_back(1LL<<i);
        }
    }
    int idx = 0;
    while ((int)v.size() < k) {
        if (v[idx] > 1) {
            long long x = v[idx];
            v[idx] = x / 2;
            v.push_back(x / 2);
        } else {
            idx++; 
        }
    }

    for (auto x : v) cout << x << " ";
    cout << "\n";

    return 0;
}
