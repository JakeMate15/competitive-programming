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
#define u_map           gp_hash_table
#define uid(a, b)       uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multi_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

vector<vector<pair<int, int>>> g;
set<int> xors;
int n, a, b;

void limpia() {
    g.clear();
    g.resize(n + 1);
    xors.clear();
}

void dfs(int nodo, int padre, int x) {
    if(nodo == b) 
        return;
    xors.insert(x);

    for(auto [v, peso]: g[nodo]) {
        if(v != padre) {
            dfs(v, nodo, peso ^ x);
        }
    }
}

bool dfs2(int nodo, int padre, int x) {
    if(nodo != b && xors.count(x))
        return true;

    for(auto [v, peso]: g[nodo]) {
        if(v != padre) {
            if(dfs2(v, nodo, peso ^ x))
                return true;
        }
    }

    return false;
}

void sol(){
    // cerr << "============\n";
    cin >> n >> a >> b;

    limpia();
    for(int i = 1; i < n; i++) {
        int u, v, w;    
        cin >> u >> v >> w;

        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    dfs(a, 0, 0);
    cout << (dfs2(b, 0, 0) ? "YES" : "NO") << "\n";


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}