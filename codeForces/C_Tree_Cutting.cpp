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
int cnt;

int dfs(int nodo, int padre, int t) {
    int tam = 1;

    for (auto u: g[nodo]) {
        if (u != padre) {
            tam += dfs(u, nodo, t);
        }
    }

    if (tam >= t) {
        cnt++;
        return 0;
    }
    return tam;
}

void sol() {
    int n, k;
    cin >> n >> k;

    g = vvi(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    int lo = 0, hi = n - 1;
    while (lo + 1 < hi) {   
        int mid = (lo + hi) / 2;
        cnt = 0;

        dfs(1, 0, mid);

        if (cnt - 1 >= k)   lo = mid;
        else    hi = mid;
    }

    cout << max(1, lo) << "\n";
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