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

string s;
vvi g;
vector<ll> dp, hijo;
ll n, res;

void dfs (int nodo, int padre) {
    dp[nodo] += (s[padre - 1] == 'L' && !hijo[nodo] || s[padre - 1] == 'R' && hijo[nodo]);
    dp[nodo] += (s[padre - 1] == 'U');
    dp[nodo] += dp[padre];

    for (auto u: g[nodo]) {
        if (u != padre) {
            dfs(u, nodo);

            if (sz(g[u]) == 1 && u != 1) {
                res = min(res, dp[u]);
            }
        }
    }

}

void sol(){
    cin >> n >> s;

    g = vvi(n + 1);
    dp = vector<ll>(n + 1);
    hijo = vector<ll>(n + 1);
    res = LONG_LONG_MAX;

    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;

        if (l != 0) {
            g[i].push_back(l);
            g[l].push_back(i);
            hijo[l] = 1;
        }
        if (r != 0) {
            g[i].push_back(r);
            g[r].push_back(i);
        }
    }

    dfs(1, 0);

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