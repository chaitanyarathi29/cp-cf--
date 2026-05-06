#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x >> s;

        int ops = 0;

        while (x.size() <= 50) {
            if (x.find(s) != string::npos) {
                cout << ops << "\n";
                break;
            }
            x += x;
            ops++;
        }

        if (x.find(s) == string::npos) {
            cout << -1 << "\n";
        }
    }
}