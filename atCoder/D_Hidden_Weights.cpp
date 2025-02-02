#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int64_t> ans(n + 1, 0);
    vector<pair<int, int64_t>> g[n + 1];
    for (int i = 0; i    < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        g[u].emplace_back(v, w);
        g[v].emplace_back(u, -w);
    }

    vector<bool> vis(n + 1);
    function<void(int)> dfs = [&] (int nodo) -> void {
        vis[nodo] = true;
        for (auto [v, w]: g[nodo]) {
            if (!vis[v]) {
                ans[v] = w + ans[nodo];
                dfs(v);
            }
        }
    };

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }

    return 0;
}