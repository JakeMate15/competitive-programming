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

vector<vector<int>> arbol;
vector<int>a,b,distInd;

void dfs(int u, int p, vector<int> &dist){
    for (auto v : arbol[u]) {
        if (v != p) {
            dist[v] = dist[u] + 1;
            dfs(v,u,dist);
        }
    }
}

void sol(){
    int n,m;
    cin>>n>>m;
    a.clear();
    arbol.clear();
    b.clear();
    distInd.clear();
    a.resize(n+1,0);
    b.resize(n+1,0);
    distInd.resize(n+1,0);
    arbol.resize(n+1);

    forn(i,n-1){
        int u,v;cin>>u>>v;
        arbol[u].push_back(v);
        arbol[v].push_back(u);
    }

    dfs(1,0,distInd);
    int n1 = max_element(all(distInd))-distInd.begin();

    dfs(n1,0,a);
    int n2 = max_element(all(a))-a.begin();

    dfs(n2,0,b);
    
    unordered_map<int,int> nodos;
    fore(i,1,n){
        int actual = max(a[i],b[i]);
        //cout << actual << " ";
        if(nodos.count(actual)){
            nodos[actual]++;
        }
        else{
            nodos[actual] = 1;
        }
    }
    
    int x = nodos[3];
    int y = nodos[4]/x;

    cout << x << " " << y << endl;
}


int main(){IO
    int t=1;cin>>t;
    while(t--)
        sol();
}


