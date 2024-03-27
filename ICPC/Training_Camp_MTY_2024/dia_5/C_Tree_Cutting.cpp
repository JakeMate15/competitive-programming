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
vector<ll> tam;

void dfs(int nodo, int padre, int t) {

    for (auto u: g[nodo]) {
        if (u != padre) {
            dfs(u, nodo, t);
            tam[nodo] += tam[u];
        }
    }
}

void sol() {
    cerr << "=============\n";
    int n, k;
    cin >> n >> k;

    g.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    int lo = -1, hi = k + 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;

        tam = vector<ll>(n + 1, 1);
        dfs(1, 0, 9);
        for (int i = 1; i <= n; i++) {
            cerr << tam[i] << " \n"[i == n];
        }

        break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}