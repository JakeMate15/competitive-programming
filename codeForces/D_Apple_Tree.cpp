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

void sol () {
    int n;
    cin >> n;

    vector<vector<int>> g(n + 1);
    vector<int> hojas(n + 1, 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    function<void(int, int)> dfs = [&] (int u, int p) -> void {
        int cnt = 0;
        for (auto v: g[u]) {
            if (v != p) {
                hojas[u] = 0;
                dfs(v, u);
                cnt += hojas[v];
            }
        }
        hojas[u] = max(cnt, hojas[u]);
    };

    dfs(1, 0);

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << 1LL * hojas[u] * hojas[v] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}