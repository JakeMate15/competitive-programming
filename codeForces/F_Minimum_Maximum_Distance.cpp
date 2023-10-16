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

vector<vector<int>> g;
vector<int> mark;
vector<int> d1, d2;

void dfs(int nodo, int padre) {
    d1[nodo] = d1[padre] + 1;
    
    for(auto u: g[nodo]) {
        if(u != padre) {
            dfs(u, nodo);
        }
    }
}

void dfs2(int nodo, int padre) {
    d2[nodo] = d2[padre] + 1;
    
    for(auto u: g[nodo]) {
        if(u != padre) {
            dfs2(u, nodo);
        }
    }
}

void sol(){
    int n, k;
    cin >> n >> k;

    g.clear();  g.resize(n + 1);
    mark.clear();   mark.resize(n + 1);
    d1.clear(); d1.resize(n + 1);
    d2.clear(); d2.resize(n + 1);

    for(int i = 1; i <= k; i++) {
        int u;
        cin >> u;
        mark[u] = 1;
    }

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    d1[0] = -1;
    dfs(1, 0);

    int mx1 = -1, n1 = -1;
    for(int i = 1; i <= n; i++) {
        if(d1[i] > mx1 && mark[i]) {
            mx1 = d1[i];
            n1 = i;
        }
    }

    d2[0] = -1;
    dfs2(n1, 0);

    int mx2 = -1, n2 = -1;
    for(int i = 1; i <= n; i++) {
        if(d2[i] > mx2 && mark[i]) {
            mx2 = d2[i];
            n2 = i;
        }
    }

    cout << (mx2 + 1) / 2 << "\n";
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