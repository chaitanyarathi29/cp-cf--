#include <iostream>
#include <vector>
#include <climits>
using namespace std;

long long helper(int i, int j, vector<vector<int>>& v, int n, int m) {

    // out of bounds
    if (i >= n || j >= m) {
        return LLONG_MIN;
    }

    // destination
    if (i == n - 1 && j == m - 1) {
        return v[i][j];
    }

    long long down = helper(i + 1, j, v, n, m);
    long long right = helper(i, j + 1, v, n, m);

    return v[i][j] + max(down, right);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    cout << helper(0, 0, v, n, m) << endl;
    return 0;
}
