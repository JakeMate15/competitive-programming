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

const int N = 2*1e5+5;
int n;
vector< vector<pair<int,int>> > arbol(N);
int tam[N];
bool valido;
vector<int> res;

void dfs(int u,int padre){
    tam[u] = 1;
    for(auto [nodo,idx]: arbol[u]){
        if(nodo == padre)   continue;
        dfs(nodo,u);
        if(tam[nodo]==3){
            res.push_back(idx);
            tam[nodo]-=3;
        }
        tam[u]+=tam[nodo];
    }
    if(tam[u]>3)    valido=false;
}

void sol(){
    cin>>n;
    valido = true;
    res.clear();

    forn(i,n-1){
        int u,v;cin>>u>>v;
        arbol[u].emplace_back(v,i+1);
        arbol[v].emplace_back(u,i+1);
    }

    dfs(1,0);
    if(valido && tam[1]==3){
        debug(res.size());
        for(auto x: res){
            cout << x << " ";
        }
        debug("");
    }
    else{
        debug(-1);
    }
    
    fore(i,1,n){
        arbol[i].clear();
    }
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}