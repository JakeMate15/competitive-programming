#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl              cout << "\n";

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multi_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

struct edge{
    int costo, u, v;

    edge(ll costo, int u, int v): costo(costo), u(u), v(v) {}
};

bool cmp(edge a, edge b) {
    return a.costo < b.costo;
}

struct DSU {
    vector<int> par;
    vector<int> rank; // rank[x] = size of the component where x belongs
 
    DSU(int n) {
        par.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            par[i] = i;
            rank[i] = 1;
        }
    }
 
    int find(int x) {
        if (par[x] == x) {
            return x;
        } 
        else {
            return (par[x] = find(par[x])); // Path Compression
        }
    }
 
    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty) {
            // both elements are in the same component
            return;
        }
        if (rank[rootx] < rank[rooty]) { // Rank Compression
            swap(rootx, rooty);
        }
        rank[rootx] += rank[rooty];
        par[rooty] = rootx;
    }

    bool same(int u, int v){
        return find(u) == find(v);
    }
};


void sol(){
    int n;
    cin >> n;

    vector<int> p(n + 1), costo(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> costo[i];
    }

    vector<edge> g;
    for(int i = 1; i <= n; i++) {
        g.emplace_back(-2 * costo[i], i, p[i]);
        g.emplace_back(-costo[i], p[i], i);
    }

    //Max Spanning Tree
    vector<vector<int>> tree(n + 1);
    vector<int> indeg(n + 1, 0);
    ll vMST = 0;
    DSU dsu(n);

    sort(all(g), cmp);
    for(auto e: g) {
        int u = e.u, v = e.v, c = -e.costo;
        if(!dsu.same(u,v)) {
            tree[u].push_back(v);
            dsu.unite(u, v);
            indeg[v]++;
            vMST += c;
        }
    }

    // toposort
    vector<int> topo;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!indeg[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        topo.push_back(curr);
        for (auto v : tree[curr]) {
            indeg[v]--;
            if (!indeg[v]) {
                q.push(v);
            }
        }
    }

    for(auto x: topo) {
        deb(x);
    }

    nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t=1;
    cin>>t;

    while(t--){
        sol();
    }

    return 0;
}