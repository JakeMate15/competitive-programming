#include<bits/stdc++.h>
using namespace std;

void dfs (int v, int p, vector<int> &d, const vector<vector<int>> &g) {
    for (auto u: g[v]) {
        if (u == p) continue;
        d[u] = d[v] + 1;
        dfs (u, v, d, g);
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> g(n + 1, vector<int>());
    for (int i = 2; i <= n; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> d1(n + 1), d2(n + 1), d3(n + 1);

    dfs(1, 0, d1, g);
    int a = max_element(d1.begin(), d1.end()) - d1.begin();

    dfs(a, 0, d2, g);
    int b = max_element(d2.begin(), d2.end()) - d2.begin();

    dfs(b, 0, d3, g);

    for (int i = 1; i <= n; i++) {
        cout << max(d2[i], d3[i]) << " \n"[i == n];
    }

    return 0;
}