#include <iostream>
#include <vector>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int i = 0, ans = 0;

        while (i < n) {
            if (s[i] == '#') {
                i++;
                continue;
            }

            int j = i;
            while (j < n && s[j] == '.') j++;

            int len = j - i;

            ans += (len + 2) / 3;  // ceil(len / 3)

            i = j;
        }

        cout << ans << "\n";
    }

    return 0;
}