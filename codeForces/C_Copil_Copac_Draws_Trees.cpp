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

vector<vector<pair<int, int>>> g;
int res;

void dfs(int v, int p, int ct) {
    res = max(res, ct);
    for(auto &[u, i] : g[v]) {
        if (i == p) continue;
        // cerr << i << " " << p << "\n";
        if (i < p) dfs(u, i, ct + 1);
        else dfs(u, i, ct);
    }
}

void sol(){
    // cerr << "===============\n";
    int n;
    cin >> n;

    g = vector<vector<pair<int, int>>>(n + 1);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }

    res = 1;
    dfs(1, -1, 1);
    cout << res << "\n";

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