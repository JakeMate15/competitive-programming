#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
const int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

bool val(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> arr(n, vector<int>(m));
        for (auto &a: arr) {
            for (auto &x: a) {
                cin >> x;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bool ok = true;

                int mn = INT_MIN;
                for (int k = 0; k < 4; k++) {
                    int x = i + dr[k], y = j + dc[k];
                    if (!val(x, y, n, m)) 
                        continue;

                    ok &= (arr[i][j] > arr[x][y]);
                    mn = max(mn, arr[x][y]);
                }

                if (ok) {
                    arr[i][j] = mn;
                }
            }
        }

        for (auto &a: arr) {
            for (auto &x: a) {
                cout << x << " ";
            }
            cout << "\n";
        }
        
    }

    return 0;
}