#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

void sol () {
    int n;
    cin >> n;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ll res = 0, cnt = 0;
    function<int(int, int)> dfs = [&] (int nodo, int padre) -> int {
        int tam = 1;
        for (auto u: g[nodo]) {
            if (u == padre) continue;
            tam += dfs (u, nodo);
        }

        ll r = 1LL * tam * (n - tam);
        if (r > res) {
            cnt = 0;
            res = r;
        }
        cnt += (r == res);

        return tam;
    };

    dfs (1, 0);

    cout << res << " " << cnt << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    // cin >> tt;

    while (tt--) {
        sol();
    }
}   