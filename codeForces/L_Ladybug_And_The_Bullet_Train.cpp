#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(lli (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"

const int maxV = 2*1e6+1;
vector<int> arbol[maxV];
int cantNodos[maxV];
int distDesde1[maxV];

void dfs(int nodo, int padre, int objetivo, int &padreObjetivo, int &abueloObjetivo){
    cantNodos[nodo] = 1;
    for(int u: arbol[nodo]){
        if(u==padre) continue;
        if(u==objetivo){
            padreObjetivo=nodo;
            abueloObjetivo=padre;
        }
        distDesde1[u] = distDesde1[nodo]+1;
        dfs(u,nodo,objetivo,padreObjetivo,abueloObjetivo);
        cantNodos[nodo]+=cantNodos[u];
    }
}

void sol(){
    int n,destino;  
    cin>>n>>destino;

    forn(i,n-1){
        int u,v;cin>>u>>v;
        arbol[u].push_back(v);
        arbol[v].push_back(u);
    }

    int padreDestino = 0,abueloDestino=0;
    dfs(1,0,destino,padreDestino,abueloDestino);

    lli nodosMalos = 0;
    for(auto x: arbol[padreDestino]){
        if(x==destino || x==abueloDestino) continue;
        nodosMalos+=cantNodos[x];
    }

    nodosMalos+=(cantNodos[destino]-1);
    
    lli ans = n*2-2-distDesde1[destino]-nodosMalos*2;
    cout << ans << endl;    
}


int main(){IO
    int t=1;//cin>>t;
    while(t--)
        sol();
    return 0;
}


