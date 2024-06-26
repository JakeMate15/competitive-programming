#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multi_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define all(v)          v.begin(), v.end()
#define rall(v)         v.rbegin(), v.rend()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

vvi g;
vector<bool> vis;
int cnt = 0;

void dfs (int nodo) {
    if (vis[nodo])  return;
    vis[nodo] = true;

    for (auto u: g[nodo]) {
        dfs(u);
    }
}

void sol() {
    int n, m;
    cin >> n >> m;

    g = vvi(n + 1, vi());
    vis = vector<bool>(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> res;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        cnt++;
        dfs(i);

        res.push_back(i);
    }

    cout << cnt - 1 << "\n";
    for (int i = 1; i < sz(res); i++) {
        cout << 1 << " " << res[i] << "\n";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}
