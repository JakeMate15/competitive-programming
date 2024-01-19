#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

vector<vector<int>> g;

void dfs(int nodoInicial, int p, vector<ll> &a) {
    stack<pair<int, int>> pila;
    pila.push({nodoInicial, 0});

    while (!pila.empty()) {
        auto [nodo, padre] = pila.top();
        pila.pop();

        for (auto u: g[nodo]) {
            if (u != padre) {
                a[u] = a[nodo] + 1;
                pila.push({u, nodo});
            }
        }
    }
}

void sol(){
    int n, k, c;
    cin >> n >> k >> c;

    g = vector<vector<int>>(n + 1);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<ll> dInd(n + 1), a(n + 1), b(n + 1);
    dfs(1, 0, dInd);
    int nodo = max_element(all(dInd)) - dInd.begin();
    
    dfs(nodo, 0, a);
    nodo = max_element(all(a)) - a.begin();

    dfs(nodo, 0, b);
    
    ll res = 0;
    for(int i = 1; i <= n; i++) {
        res = max(res, max(a[i], b[i]) * k - dInd[i] * c);
    }
    cout << res << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}