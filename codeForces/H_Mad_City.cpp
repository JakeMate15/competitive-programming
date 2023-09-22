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

vector<vi> g;
vi vis;
set<int> ciclo;
int entrada;

void dfs(int u, int padre) {
    vis[u] = true;

    for(auto v: g[u]) {
        if(v == padre) continue;

        if(vis[v]) {
            if(entrada == -1) {
                entrada = v;
            }
            continue;
        }
        dfs(v,u);
    }
}

int bfs(int inicio, int destino, int n) {
    vi dist(n+1);
    vector<bool> ya(n+1,false);
    queue<int> q;

    q.push(inicio);
    ya[inicio] = true;
    dist[inicio] = 0;

    while(!q.empty()) {
        int actual = q.front();q.pop();

        for(auto u: g[actual]) {
            if(ya[u]) {
                continue;
            }

            ya[u] = true;
            dist[u] = dist[actual] + 1;
            q.push(u);
        }
    }

    return dist[destino];
}

void sol(){
    int n, ma, va;
    cin >> n >> ma >> va;

    g.clear();g.resize(n+1,{});
    vis.clear();vis.resize(n+1,0);
    entrada = -1;


    forn(i,n) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    if(ma == va) {
        debln("NO");
        return;
    }

    dfs(va, 0);
    
    if(entrada == va) {
        debln("YES");
        return;
    }
    
    int distV = bfs(va, entrada, n);
    int distM = bfs(ma, entrada, n);

    debln((distM <= distV? "NO": "YES"));
}

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);

    int t=1;
    cin>>t;
    while(t--){
        sol();
    }

    return 0;
}