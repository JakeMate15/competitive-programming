#include<bits/stdc++.h>
using namespace std;

#define forn(i,n)       for(int i=0; i<n; i++)
#define forr(i,a,n)     for(int i=a; i<n; i++)
#define fore(i,a,n)     for(int i=a; i<=n; i++)
#define fornd(i,n)      for(int i=n; i>=0; i--)
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define pb              push_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const int mx = 1e5+10;
vi g[mx];
int vis[mx], col[mx];
map<int,int> colores;

void sol(){
    int n,x;
    cin>>n;

    forn(i,n-1){
        int u,v;
        cin>>u>>v;

        g[u].pb(v);
        g[v].pb(u);
    }

    cin>>x;
    queue<int> q;
    vis[1] = col[1] = 1;
    q.push(1);
    int color = 1;
    while(!q.empty()){
        int s = q.front();q.pop();
        for(auto u: g[s]){
            if(vis[u])  continue;
            vis[u] = true;
            col[u] = col[s]+1;
            q.push(u);
        }
        
    }

    fore(i,1,n){
        colores[col[i]]++;
    }
    debln(colores[x]);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int t=1;
    //cin>>t;
    while(t--){
        sol();
    }

    return 0;
}