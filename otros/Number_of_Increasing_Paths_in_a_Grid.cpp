#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "/algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

class Solution {
private:
    const int MOD = 1E9 + 7;
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

public:
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> paths(n, vector<int>(m, 1)), vis(n, vector<int>(m, 0));

        function<bool(int, int)> outsideGrid = [&] (int x, int y) -> bool {
            return x < 0 || x >= n || y < 0 || y >= m;
        };

        function<int(int, int)> dfs = [&] (int x, int y) -> int {
            if (vis[x][y])
                return paths[x][y];
            vis[x][y] = 1;

            for (int i = 0; i < 4; i++) {
                int nX = x + dx[i];
                int nY = y + dy[i];

                if (!outsideGrid(nX, nY) && grid[nX][nY] > grid[x][y]) {
                    (paths[x][y] += dfs(nX, nY)) %= MOD;
                }
            }
            
            return paths[x][y];
        };

        int increasingPaths = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    dfs(i, j);
                }
                (increasingPaths += paths[i][j]) %= MOD;
            }
        }

        return increasingPaths;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>(m));
    for (auto &x: g) {
        for (auto &y: x) {
            cin >> y;
        }
    }

    Solution sol;
    cout << sol.countPaths(g) << "\n";

    return 0;
}

