#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;

    N--;

    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }

    string ans = "";

    while (N > 0) {
        int digit = N % 5;
        ans += char('0' + digit * 2);
        N /= 5;
    }

    reverse(ans.begin(), ans.end());

    cout << ans << endl;

    return 0;
}