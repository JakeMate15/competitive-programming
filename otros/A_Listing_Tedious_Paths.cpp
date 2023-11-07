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
const int MX = 1e5 + 5;

int cnt[MX], res[MX], ans[MX], c[MX];

struct cd {
    int sz[MX];
    bool listo[MX];
    vector<array<int, 2>> t[MX];

    void dfs1(int u, int p, int add) {
        cnt[c[u]] += add;
        if (cnt[c[u]] < 0) {
            cnt[c[u]] = 0;
        }

        for (auto e : t[u]) {
            int v = e[0];
            if (v == p || listo[v]) {
                continue;
            }
            dfs1(v, u, add);
        }
    }

    void dfs2(int u, int p) {
        res[u] = cnt[c[u]];
        for (auto e : t[u]) {
        int v = e[0], eid = e[1];
        if (v == p || listo[v]) {
            continue;
        }
        dfs2(v, u);
        res[u] += res[v];
        ans[eid] += res[v];
        }
    }

    void solve(int u) {
        dfs1(u, -1, 1);

        for (auto e : t[u]) {
            int v = e[0], eid = e[1];
            if (listo[v]) {
                continue;
            }
            dfs1(v, u, -1);
            dfs2(v, u);
            dfs1(v, u, 1);
            ans[eid] += res[v];
        }
        dfs1(u, -1, -MX);
        listo[u] = true;
    }

    void fc(int u, int p) {
        for (auto e : t[u]) {
            int v = e[0];
            if (v == p || listo[v]) {
                continue;
            }
            if (sz[v] > (sz[u] >> 1)) {
                sz[u] -= sz[v];
                sz[v] += sz[u];
                fc(v, u);
                return;
            }
        }

        solve(u);

        for (auto e : t[u]) {
            int v = e[0];
            if (!listo[v]) {
                fc(v, u);
            }
        }
    }
};

void sol(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    cd c;

    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;

        c.t[a].push_back({b, i});
        c.t[b].push_back({a, i});
    }

    c.fc(1, -1);
    for (int i = 0; i < n-1; ++i) {
        if (i > 0) {
            cout << " ";
        }
        cout << ans[i];
    }
    nl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t=1;
    //cin>>t;

    while(t--){
        sol();
    }

    return 0;
}
