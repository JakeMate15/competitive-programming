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

void sol() {
    int n, m;
    cin >> n >> m;

    vector<vector<ii>> g(n + 1);
    map<int, int> nvoNodo;
    int aux = n + 3;
    for (int i = 0; i < m; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        
        g[u].emplace_back(v, l);
        g[v].emplace_back(u, l);

        if (!nvoNodo.count(l)) {
            nvoNodo[l] = aux++;
        }
    }

    vvi ng(n + sz(nvoNodo) + 5);
    for (int i = 1; i <= n; i++) {
        for (auto [u, l]: g[i]) {
            int no = nvoNodo[l];
            ng[i].push_back(no);
            ng[no].push_back(i);
            ng[u].push_back(no);
            ng[no].push_back(u);
        }
    }

    int incio, fin;
    cin >> incio >> fin;

    vector<bool> vis(sz(ng));
    vector<ll> dis(sz(ng));
    queue<int> q;

    q.push(incio);
    vis[incio] = true;
    dis[incio] = 0;

    while (!q.empty()) {
        int nodo = q.front();
        q.pop();

        for (auto u: ng[nodo]) {
            if (vis[u]) continue;

            dis[u] = dis[nodo] + 1;
            vis[u] = true;
            q.push(u);
        }
    }

    cout << dis[fin] / 2 << "\n";
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