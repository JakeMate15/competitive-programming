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

void sol(int n, int k, int m) {
    // cerr << "===========\n";
    vector<bool> cerrados(n + 1);
    vector<int> llave(n + 1);

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;

        cerrados[b] = true;
        llave[a] = b;
    }

    // for (int i = 1; i <= n; i++) {
    //     cerr << cerrados[i] << " \n"[i == n];
    // }
    // for (int i = 1; i <= n; i++) {
    //     cerr << llave[i] << " \n"[i == n];
    // }

    vvi g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<bool> vis(n + 1);
    queue<int> q;
    set<int> pendiente;
    vis[1] = true;
    q.push(1);
    while(!q.empty()) {
        int u = q.front(); 
        q.pop();

        if (cerrados[u]) {
            pendiente.insert(u);
            continue;
        }
        
        if (llave[u] != 0) {
            cerrados[llave[u]] = false;
            if (pendiente.count(llave[u])) {
                q.push(llave[u]);
                pendiente.erase(llave[u]);
            }
        }

        // cerr << u << " ";

        // if (llaves[u] != 0) {
        //     cerr << u << " ";
        // }

        for(auto v: g[u]) {
            if(!vis[v]) {
                q.push(v);
                vis[v] = 1;
            }
        }
    }

    // cerr << "\n";
    cout << (vis[n] ? 'Y' : 'N') << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int n, k, m;

    while(cin >> n >> k >> m) {
        if (n == -1)    return 0;
        sol(n, k, m);
    }

    return 0;
}