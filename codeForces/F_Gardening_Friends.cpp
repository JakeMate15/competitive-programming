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
lli n,largo,costo;
vector<vector<int>> arbol;


void dfs(int u, int p, vector<lli> &dist){
    for (auto v : arbol[u]) {
        if (v != p) {
            dist[v] = dist[u] + 1;
            dfs(v,u,dist);
        }
    }
}

void sol(){
    cin>>n>>largo>>costo;
    vector<lli> distMaxima1(n+1,0),distMaxima2(n+1,0),dist(n+1,0);
    arbol.clear();
    arbol.resize(n+1);

    forn(i,n-1){
        int u,v;cin>>u>>v;
        arbol[u].push_back(v);
        arbol[v].push_back(u);
    }

    dfs(1,0,dist);
    int a=0,b=0;
    fore(i,1,n){
        if(dist[i]>dist[a])
            a=i;
    }

    dfs(a,0,distMaxima1);
    fore(i,1,n){
        if(distMaxima1[i]>distMaxima1[b])
            b=i;
    }

    dfs(b,0,distMaxima2);

    //fore(i,1,n)   cout << max(distMaxima1[i],distMaxima2[i]) << " ";
    //cout << endl;

    lli ans = -1;
    fore(i,1,n) ans = max(ans,largo*(max(distMaxima1[i],distMaxima2[i]))-dist[i]*costo);
    cout << ans << endl;
    
    //cout << *max_element( costos,costos+n+1 ) << endl;
}


int main(){
    int t=1;cin>>t;
    while(t--)
        sol();
}


