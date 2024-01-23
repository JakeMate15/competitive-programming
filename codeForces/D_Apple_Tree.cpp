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

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

vector<vector<int>> g;
vector<ll> dp;

void dfs(int nodo, int padre) {

    for (auto u: g[nodo]) {
        dp[u] += (sz(g[u]) == 1 && u != 1);

        if(u != padre) {
            dfs(u, nodo);
            dp[nodo] += dp[u]; 
        }
    }

}

void sol(){
    int n;
    cin >> n;

    g = vector<vector<int>>(n + 1);
    dp = vector<ll>(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);

    // for(int i = 1; i <= n; i++) {
    //     cout << dp[i] << " \n"[i == n];
    // }

    int q;
    cin >> q;
    while(q--) {
        int u, v;
        cin >> u >> v;

        cout << dp[u] * dp[v] << "\n";
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