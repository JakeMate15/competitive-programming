#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()

typedef long long ll;
typedef pair<int, int> ii;

struct DSU {
    vector<int> par;
    vector<int> rank;
    int tam;

    DSU (int n) {
        par.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            par[i] = i;
            rank[i] = 1;
        }
    }

    int find (int x) {
        return (par[x] == x ? x : par[x] = find(par[x]));
    }
    
    void unite (int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry)
            return;
        if (rank[rx] < rank[ry])
            swap(rx, ry);
        rank[x] += rank[ry];
        par[ry] = rx;
        tam--;
    }

    bool same (int u, int v) {
        return find(u) == find(v);
    }
};

void sol () {
    int n, m, d;
    cin >> n >> m >> d;

    vector<ii> a(m), res;
    vector<int> vis(n + 1);
    vector<vector<int>> g(n + 1);
    for (auto &[a, b]: a) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    if (g[1].size() < d) {
        cout << "NO\n";
        return;
    }

    function<void(int)> dfs = [&] (int nodo) -> void {
        vis[nodo] = 1;

        for (auto u: g[nodo]) {
            if (vis[u])
                continue;
            dfs(u);
        }   
    };

    DSU ds(n);
    vis[1] = 1;
    set<int> aux;
    for (auto u: g[1]) {
        if (vis[u])
            continue;

        dfs(u);
        aux.insert(u);
    }

    if (aux.size() > d) {
        cout << "NO\n";
        return;
    }

    for (auto u: aux) {
        ds.unite(1, u);
        res.emplace_back(1, u);
        d--;
    }

    for (auto u: g[1]) {
        if (aux.count(u))
            continue;
        if (d <= 0)
            break;

        ds.unite(1, u);
        res.emplace_back(1, u);
        d--;
    }

    for (auto [a, b]: a) {
        if (min(a, b) == 1) 
            continue;
        if (!ds.same(a, b)) {
            res.emplace_back(a, b);
            ds.unite(a, b);
        }
    }

    cout << "YES\n";
    for (auto [a, b]: res) {
        cout << a << " " << b << "\n";
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;

    while (t--) {
        sol();
    }

    return 0;
}