#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

#define sz(a)       (int) a.size()
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int MX = 2E5 + 5;
const int MOD = 1E9 + 7;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1}; 

        queue<pair<int, int>> q; 
        vector<vector<int>> distance(n, vector<int>(m, -1));
        function<bool(int, int)> validPosition = [&] (int x, int y) -> bool {
            return x >= 0 && x < n && y >= 0 && y < m && distance[x][y] == -1;
        };

        function<void(int, int)> dfs = [&] (int x, int y) -> void {
            if (!validPosition(x, y) || grid[x][y] == 0) {
                return;
            }

            distance[x][y] = 0;
            q.emplace(x, y);
            
            for (int i = 0; i < 4; i++) {
                dfs(x + dx[i], y + dy[i]);
            }
        };

        bool find = false;
        for (int i = 0; i < n && !find; i++) {
            for (int j = 0; j < m && !find; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j);
                    find = true;
                }
            }
        }

        int minimunFlips = n * m;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nX = x + dx[i], nY = y + dy[i];
                if (validPosition(nX, nY)) {
                    distance[nX][nY] = distance[x][y] + 1;
                    if (grid[nX][nY] == 1) {
                        minimunFlips = min(minimunFlips, distance[nX][nY]);
                    }
                    q.emplace(nX, nY);
                }
            }
        }

        return minimunFlips - 1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>(n, 0));
    for (auto &x: g) {
        for (auto &y : x) {
            cin >> y;
        }
    }

    Solution sol;

    cout << sol.shortestBridge(g) << "\n";

    return 0;
}