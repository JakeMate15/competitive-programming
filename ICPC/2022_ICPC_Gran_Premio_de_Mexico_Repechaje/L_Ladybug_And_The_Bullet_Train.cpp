#include<bits/stdc++.h>
using namespace std;

#define sz(a)   (int)a.size()
#define all(a)  a.begin(), a.end()

typedef long long ll;

vector<vector<int>> g;
vector<ll> dp, dp2;

void dfs(int nodo, int padre, int m, int &pObj, int &aObj){
    dp[nodo] = 1;
    for(int u: g[nodo]){
        if(u == padre) continue;
        if(u == m){
            pObj = nodo;
            aObj = padre;
        }

        dp2[u] = dp2[nodo] + 1;
        dfs(u, nodo, m, pObj, aObj);
        dp[nodo] += dp[u];
    }
}


int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, d;
    cin >> n >> d;

    g.resize(n + 1);
    dp.resize(n + 1);
    dp2.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    int pD = 0, aD = 0;
    dfs(1, 0, d, pD, aD);

    ll nodosMalos = 0;
    for(auto x: g[pD]){
        if(x == d || x == aD) continue;
        nodosMalos += dp[x];
    }

    nodosMalos += (dp[d] - 1);
    
    cout << (n * 2 - 2 - dp2[d] - nodosMalos * 2) << endl;    
}