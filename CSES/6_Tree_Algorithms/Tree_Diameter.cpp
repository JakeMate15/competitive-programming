#include<bits/stdc++.h>
using namespace std;

int d = 0;

int dfs (int v, int p, const vector<vector<int>> &g) {
    int maxDeph = 0, seconDeph = 0;
    for (auto u: g[v]) {
        if (u != p) {
            int currDeph = dfs(u, v, g) + 1;
            if (currDeph > maxDeph) {
                seconDeph = maxDeph;
                maxDeph = currDeph;
            } else if (currDeph > seconDeph) {
                seconDeph = currDeph;
            } 
        }
    }
    d = max(d, maxDeph + seconDeph);
    return maxDeph;
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

    dfs(1, 0, g);

    cout << d << "\n";

    return 0;
}