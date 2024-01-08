#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 1e5 + 5;

int n;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v, int par) {
    visited[v] = true;
    for (int u : adj[v]) {
        if(u == par) continue;
        if (visited[u]) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        parent[u] = v;
        if (dfs(u, parent[u]))
            return true;
    }
    return false;
}

void sol() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    visited.assign(n +1 , false);
    parent.assign(n + 1, -1);
    cycle_start = -1;

    for (int v = 1; v <= n; v++) {
        if (!visited[v] && dfs(v, parent[v]))
            break;
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE" << endl;
    } 
    else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);

        cout << sz(cycle) << "\n";
        for (int v : cycle)
            cout << v << " ";
        nl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}