//https://cses.fi/problemset/result/5968107/
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
 
const int maxV = 2*1e5+1;
vector<vector<int>> arbol;
int cantNodos[maxV];
 
void dfs(int nodo, int padre){
    cantNodos[nodo] = 1;
    for(int u: arbol[nodo]){
        if(u==padre) continue;
        dfs(u,nodo);
        cantNodos[nodo]+=cantNodos[u];
    }
}
 
void sol(){  
    int n;  
    cin>>n;
    arbol.resize(n+1);
    memset(cantNodos,0,sizeof(cantNodos));
 
    forr(i,2,n+1){
        int emp;cin>>emp;
        arbol[emp].push_back(i);
        arbol[i].push_back(emp);
    }
 
    dfs(1,0);
    fore(i,1,n) cout << cantNodos[i]-1 << " ";
}
 
 
int main(){IO
    int t=1;//cin>>t;
    while(t--)
        sol();
}