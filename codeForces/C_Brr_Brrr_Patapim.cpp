#include<bits/stdc++.h>
using namespace std;

void sol () {
    int n;
    cin >> n;

    vector<int> p(2 * n), vis(2 * n + 1);
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
            if (mat[i][j] <= 2 * n) {
                p[i + j + 1] = mat[i][j];
                vis[mat[i][j]] = 1;
            }
        }
    }

    int curr = 1;
    for (int i = 0; i < 2 * n; i++) {
        if (p[i] == 0) {
            while (vis[curr]) {
                curr++;
            }
            vis[curr] = 1;
            p[i] = curr;
        }
    }

    for (int i = 0; i < 2 * n; i++) {
        cout << p[i] << " \n"[i == 2 * n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}