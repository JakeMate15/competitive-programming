#include<bits/stdc++.h>
using namespace std;

#define sz(a)   (int)a.size()
#define all(a)  a.begin(), a.end()

typedef long long ll;
const int MX = 100;

const int dc[] = {1, -1, 0, 0};
const int dr[] = {0, 0, 1, -1};

int n, m, g[MX][MX];

bool ok(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    int res = 10;
    for (int i = 1; i < (1 << 10); i++) {
        if (res <= __builtin_popcount(i))   continue;

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        if (i & (1 << (g[x1][y1] - 1))) {
            q.emplace(x1, y1);
            vis[x1][y1] = true;
        }

        while (!q.empty()) {
            auto[x, y] = q.front();
            q.pop();

            // cerr << x << " " << y << "\n";

            for (int j = 0; j < 4; j++) {
                int nx = x + dc[j], ny = y + dr[j];
                if (ok(nx, ny) && !vis[nx][ny]) {
                    
                    int num = g[nx][ny];
                    if (i & (1 << (num - 1))) {
                        q.emplace(nx, ny);
                        vis[nx][ny] = true;
                    } 
                }
            }
        }

        if (vis[x2][y2]) {
            // cerr << i << "\n";
            res = min(res, __builtin_popcount(i));
        }
    }

    cout << res << "\n";
    
}


