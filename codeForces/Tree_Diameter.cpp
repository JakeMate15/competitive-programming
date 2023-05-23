#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(lli (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"

const int maxV = 2*1e5+1;
vector<vector<int>> arbol;

void dfs(int nodo, int padre, vi &a){
    for(auto u: arbol[nodo]){
        if(u==padre)    continue;
        a[u] = a[nodo]+1;
        dfs(u,nodo,a);
    }
}

void sol(){  
    int n;  
    cin>>n;
    arbol.resize(n+1);
    vi a(n+1),b(n+1);

    forn(i,n-1){
        int u,v;cin>>u>>v;
        arbol[u].push_back(v);
        arbol[v].push_back(u);
    }

    dfs(1,0,a);
    int d1 = max_element(all(a))-a.begin();

    dfs(d1,0,b);
    int d2 = max_element(all(b))-b.begin();

    cout << max(a[d1],b[d2]) << endl;
}


int main(){IO
    int t=1;//cin>>t;
    while(t--)
        sol();
}


