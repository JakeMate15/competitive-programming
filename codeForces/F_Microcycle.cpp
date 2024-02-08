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
    return a.costo < b.costo;
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

vector<vector<ii>> t;
vector<int> curr, vis;
int mnC;

void dfs(int nodo, int padre) {
    curr.push_back(nodo);
    vis[nodo] = 1;

    for (auto [u, c]: t[nodo]) {
        if (u != padre) {
            mnC = min(mnC, c);
            dfs(u, nodo);
        }
    }
}

void sol(){
    // cerr << "===========\n";
    int n, m;
    cin >> n >> m;

    vector<edge> g;
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        g.emplace_back(c, u, v);
    }

    sort(all(g), cmp);
    DSU ds(n);
    t = vector<vector<ii>>(n + 1);

    for (auto [c, u, v]: g) {
        if (!ds.same(u, v)) {
            t[u].emplace_back(v, c);
            t[v].emplace_back(u, c);
            ds.unite(u, v);
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     cerr << i << ": \n";
    //     for (auto [u, c]: t[i]) {
    //         cerr << "(" << u << "," << c << ") ";
    //     }
    //     cerr << "\n";
    // }

    int mn = INT_MAX;
    vector<int> res;
    vis = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            curr.clear();
            mnC = INT_MAX;
            dfs(i, 0);

            if (mnC < mn) {
                mn = mnC;
                res = curr;
            }
        }
    }

    cout << mn << " " << sz(res) << "\n";
    for (int i = 0; i < sz(res); i++) {
        cout << res[i] << " \n"[i == sz(res) - 1];
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