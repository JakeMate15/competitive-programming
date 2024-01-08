#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 505;

void sol(){
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> g(n + 1, vector<ll>(n + 1, 1e18));

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        g[u][v] = g[v][u] = min(1ll * w, g[u][v]);
    }

    for(int i = 1; i <= n; i++) {
        g[i][i] = 0;
    }

    for(int k = 1; k <= n; k++) {
        for(int u = 1; u <= n; u++) {
            for(int v = 1; v <= n; v++) {
                g[u][v] = g[v][u] = min({g[u][v], g[v][u], g[u][k] + g[k][v]});
            }
        }
    }

    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << (g[u][v] == 1e18 ? -1 : g[u][v]) << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}