#include<bits/stdc++.h>
using namespace std;

const int INF = 1E9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> pos(n);
    for (auto &[x, y]: pos) {
        cin >> x >> y;
    }

    vector<vector<int>> g(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> vis(n);
    int minX = INF, maX = -INF;
    int minY = INF, maY = -INF;
    function<void(int)> dfs = [&](int nodo) -> void {
        vis[nodo] = 1;

        auto [x, y] = pos[nodo];

        minX = min(minX, x);
        maX = max(maX, x);

        minY = min(minY, y);
        maY = max(maY, y);

        for (auto v: g[nodo]) {
            if (!vis[v]) {
                dfs(v);
            }
        }
    };

    int ans = INF;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            minX = INF, maX = -INF;
            minY = INF, maY = -INF;

            dfs(i);

            int dx = maX - minX;
            int dy = maY - minY;

            ans = min(ans, 2 * dx + 2 * dy);
        }
    }

    cout << ans << "\n";

    return 0;
}