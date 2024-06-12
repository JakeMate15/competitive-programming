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

void sol() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> ant(n + 1, -1);
    queue<int> q;
    q.push(1);
    ant[1] = 0;

    while (!q.empty()) {
        int nodo = q.front();
        q.pop();

        for (auto u: g[nodo]) {
            if (ant[u] != -1)   continue;

            ant[u] = nodo;
            q.push(u);
        }
    }

    if (ant[n] == -1) {
        cout << "IMPOSSIBLE";
        return;
    }

    vector<int> res;
    for (int u = n; u != 0; u = ant[u]) {
        res.push_back(u);
    }
    reverse(all(res));

    cout << sz(res) << "\n";
    for (auto x: res) {
        cout << x << " ";
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
