//https://codeforces.com/contest/1843/problem/D
#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(lli (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"

vector< vector<lli> > arbol;
vector<lli> hojas;

void dfs(lli nodo, lli padre) {
    lli contador_hojas = 0;

    // Recorrer los nodos adyacentes
    for (auto adyacente : arbol[nodo]) {
        if (adyacente != padre) {
            dfs(adyacente, nodo);
            contador_hojas += hojas[adyacente];
        }
    }

    if (contador_hojas == 0) {
        contador_hojas = 1;  // El nodo actual es una hoja
    }

    hojas[nodo] = contador_hojas;
}

void sol(){
    lli n; cin >> n;
    arbol.clear();
    arbol.resize(n + 1);
    hojas.clear();
    hojas.resize(n + 1);

    forn(i, n - 1){
        lli u, v; cin >> u >> v;
        arbol[u].push_back(v);
        arbol[v].push_back(u);
    }

    dfs(1,0);

    lli q;cin>>q;
    while(q--){
        lli x,y;cin>>x>>y;
        debug( hojas[x]*hojas[y] );
    }

    
    
}

int main(){
    IO
    int t = 1;
    cin >> t;
    while (t--) sol();
}
