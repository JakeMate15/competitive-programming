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

typedef long double ld;
typedef pair<int, int> ii;

const int MX = 2E5 + 5;
const int MOD = 1E9 + 7;

void sol () {
    int n;
    cin >> n;

    vector<int> g[n + 1];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> from(n + 2), to(n + 2);
    function<int(int, int, int)> dfs = [&] (int u, int p, int h) -> int {
        int maxHeight = h;
        for (auto v: g[u]) {
            if (v != p) {
                from[h + 1]++;
                maxHeight = max(maxHeight, dfs(v, u, h + 1));
            }
        }
        to[maxHeight]++;
        return maxHeight;
    };

    dfs(1, 0, 0);

    for (int i = n; i >= 1; i--) {
        from[i] += from[i + 1];
    }
    for (int i = 1; i <= n; i++) {
        to[i] += to[i - 1];
    }

    int ans = n - 1;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, from[i + 1] + to[i - 1]);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}