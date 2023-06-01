//https://cses.fi/problemset/task/1666
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

const int N = 1e5+5;
vector<int> grafo[N];
bool vis[N];

void dfs(int inicio){
    if(vis[inicio]) return;
    vis[inicio] = true;

    for(auto x: grafo[inicio]){
        dfs(x);
    }
}

void sol(){
    int n,m;cin>>n>>m;
    memset(vis,0,sizeof(vis));

    int inicio = 0;
    forn(i,m){
        int u,v;cin>>u>>v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
        inicio = u;
    }

    dfs(inicio);

    vector<int> res;
    fore(i,1,n){
        if(!vis[i]){
            res.push_back(i);
            dfs(i);
        }
    }

    debug(res.size());
    for(int x: res){
        cout << inicio << " " << x << "\n";
    }

}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}