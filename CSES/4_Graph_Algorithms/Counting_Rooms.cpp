#include<bits/stdc++.h>
using namespace std;

const int dr[] = {1,-1,0,0,1,-1,-1,1};
const int dc[] = {0,0,1,-1,1,1,-1,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> g(n + 5);
    vector<vector<bool>> vis(n + 5, vector<bool>(m + 5));

    for(int i = 0; i < n; i++) {
        cin >> g[i];
    }

    auto ok = [&] (int x, int y) -> bool {
        return x >= 0 && x < n && y >= 0 && y < m && g[x][y] == '.';
    };

    function<void(int, int)> dfs = [&] (int x, int y) {
        if (!ok(x, y) || vis[x][y])
            return;
        
        vis[x][y] = true;
        dfs(x + 1, y);
        dfs(x, y + 1);
        dfs(x - 1, y);
        dfs(x, y - 1);
    };

    int res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && g[i][j] == '.') {
                res++;
                dfs(i, j);
            }
        }
    }

    cout << res << "\n";

    return 0;
}