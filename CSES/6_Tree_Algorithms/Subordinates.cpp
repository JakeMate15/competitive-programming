#include<bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> g[n + 1];
    for (int i = 2; i <= n; i++) {
        int u;
        cin >> u;

        g[u].push_back(i);
        g[i].push_back(u);
    }

    vector<int> dp(n + 1);
    function<void(int, int)> dfs = [&](int nodo, int padre) -> void {
        dp[nodo] = 1;
        for (auto u: g[nodo]) {
            if (padre != u) {
                dfs(u, nodo);
                dp[nodo] += dp[u];
            }
        }
    };

    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << dp[i] - 1 << " \n"[i == n];
    }

    return 0;
}