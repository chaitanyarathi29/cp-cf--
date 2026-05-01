#include <iostream>
#include <vector>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (k == 1) {
            // Check if already sorted
            bool sorted = true;
            for (int i = 1; i < n; i++) {
                if (a[i] < a[i - 1]) {
                    sorted = false;
                    break;
                }
            }

            cout << (sorted ? "YES\n" : "NO\n");
        } else {
            // k >= 2 → always possible
            cout << "YES\n";
        }
    }

    return 0;
}