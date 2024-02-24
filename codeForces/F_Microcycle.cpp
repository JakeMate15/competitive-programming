#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multi_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

struct edge{
    int costo, u, v;

    edge(ll costo, int u, int v): costo(costo), u(u), v(v) {}
};

bool cmp(edge a, edge b) {
    return a.costo > b.costo;
}

struct DSU {
    vector<int> par;
    vector<int> rank; // rank[x] = size of the component where x belongs
    int tam;
 
    DSU(int n) {
        par.resize(n + 1);
        rank.resize(n + 1);
        tam = n;
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
        tam--;
    }

    bool same(int u, int v){
        return find(u) == find(v);
    }
};

vector<vector<int>> t;
vector<int> r, curr;
int U, V;

void dfs(int u, int p) {
    cerr << u << " ";
    r.push_back(u);
    // if (u == V) {
    //     return;
    // }

    for (auto v: t[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
}

void sol(){
    cerr << "===========\n";
    int n, m;
    cin >> n >> m;

    vector<edge> g;
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        g.emplace_back(c, u, v);
    }

    sort(all(g), cmp);

    // for (auto [c, u, v]: g) {
    //     cerr << c << " " << u << " " << v << "\n";
    // }

    int res = INT_MAX;
    DSU ds(n);

    t = vector<vector<int>>(n + 1);
    for (auto [c, u, v]: g) {
        if (ds.same(u, v)) {
            res = c;
            U = u;
            V = v;
        }
        else {
            t[u].push_back(v);
            t[v].push_back(u);
            ds.unite(u, v);
        }
    }

    r.clear();
    dfs(U, 0);

    cerr << "\n\n" << U << " " << V << "\n\n";

    for (int i = 0; i <= n; i++) {
        for (auto x: t[i]) {
            cerr << i << " " << x << "\n";
        }
    }
    
    cout << res << " " << sz(r) << "\n";
    for (int i = 0; i < sz(r); i++) {
        cout << r[i] << " \n"[i == sz(r) - 1];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}