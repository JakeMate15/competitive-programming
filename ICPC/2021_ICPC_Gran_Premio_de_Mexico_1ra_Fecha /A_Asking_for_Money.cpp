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

vvi g;
vector<bool> vis;
vector<int> cnt;

void dfs(int nodo) {
    if (vis[nodo])  return;
    vis[nodo] = true;
    cnt[nodo]++;

    for (auto u: g[nodo]) {
        dfs(u);
    }
}

void sol() {
    int n;
    cin >> n;

    g = vvi(n + 1);
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
    }

    for (int i = 1; i + 2 <= n; i++) {
        vis = vector<bool> (n + 1);
        cnt = vector<int> (n + 1);

        
        dfs(i);
        dfs(i + 1);
        dfs(i + 2);

        cerr << "==============\n";
        for (auto x: cnt) {
            cerr << x << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    //cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}