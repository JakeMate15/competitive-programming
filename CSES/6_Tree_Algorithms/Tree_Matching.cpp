#include<bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> g[n + 1];
    for (int i = 2; i <= n; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<vector<int>> dp(n + 1, vector<int>(2));
    function<void(int, int)> dfs = [&](int v, int p) -> void {
	    for (int to : g[v]) {
            if (to != p) {
                dfs(to, v);
                dp[v][0] += max(dp[to][0], dp[to][1]);
            }
	    }

        for (int to : g[v]) {
            if (to != p) {
                dp[v][1] = max(dp[v][1], dp[to][0] + 1 + dp[v][0] - max(dp[to][0], dp[to][1]));

            }
        }
    };

    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]) << "\n";

    return 0;
}