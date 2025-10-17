#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int cnt = 0;
    vector<int> vis(n + 1);
    function<void(int)> dfs = [&] (int v) {
        cnt++;
        vis[v] = 1;
        for (auto u : g[v]) {
            if (!vis[u]) {
                dfs(u);
            }
        }
    };

    int64_t ans = -m;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cnt = 0;
            dfs(i);
            ans += cnt * 1LL * (cnt - 1) / 2;
        }
    }

    cout << ans << "\n";

    return 0;
}