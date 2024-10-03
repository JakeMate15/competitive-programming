#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<char>> g(n, vector<char>(2 * n + 2, '.'));
    g[0][n] = '*';

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= 2 * n - 1; j++) {
            int cnt = (g[i - 1][j - 1] == '*');
            cnt += (g[i - 1][j + 1] == '*');

            if (cnt == 1) {
                g[i][j] = '*';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 2 * n - 1; j++) {
            cout << g[i][j];
        }
        cout << "\n";
    }


    return 0;
}