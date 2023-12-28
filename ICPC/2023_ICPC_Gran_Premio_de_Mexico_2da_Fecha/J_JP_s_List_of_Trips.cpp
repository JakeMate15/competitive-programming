#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

vector<vector<int>> g;
vector<bool> visited;
vector<int> tin, low;
int timer;

vector<int> malo;
void dfs(int v, int p) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : g[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] <= tin[v]) {
                malo[v] = true;
                malo[to] = true;
            }   
        }
    }
}

vector<int> componente;
int cnt = 1;
void dfs2(int nodo) {
    if(componente[nodo] || malo[nodo]) {
        return;
    }

    componente[nodo] = cnt;
    for(auto u: g[nodo]) {
        dfs2(u);
    }
}

void sol(){
    int n, m, q;
    cin >> n >> m >> q;

    g.resize(n + 1);
    timer = 0;
    visited.resize(n + 1, false);
    tin.resize(n + 1, -1);
    low.resize(n + 1, -1);
    componente.resize(n + 1, 0);
    malo.resize(n + 1, 0);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);
    for(int i = 1; i <= n; i++) {
        if(!componente[i]) {
            dfs2(i);
            cnt++;
        }
    }

    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << (componente[u] && componente[v] && componente[u] == componente[v] ? "YES" : "NO") << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}