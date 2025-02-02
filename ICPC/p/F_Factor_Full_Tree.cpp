#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int64_t> ans(n + 1);
    ans[1] = ans[0] = 1;
    int64_t val = 1;
    function<void(int, int)> dfs = [&] (int u, int p) -> void {
            ans[u] = val;
            val *= 2;
        
        // cerr << u << "\n";

        for (auto v: g[u]) {
            if (v != p) {
                dfs(v, u);
            }
        }
    };

    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }

    return 0;
}