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
    // cerr << "==========\n";
    int n, m; 
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v; ll w; 
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
 
    vector<ll> nums(n + 1); 
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, 1e17));
    dist[1][1] = 0;
    set<tuple<ll,ll,ll>> pq = {{0, 1, 1}};

    while (pq.size()) {
        ll d, u, b; 
        tie(d, u, b) = *pq.begin(); 
        pq.erase(pq.begin());

        // cerr << "Vamos a procesar " << d << " " << u << " " << b << "\n";
        // cerr << "---------------------------\n";

        for (auto [v, w] : adj[u]) {
            // cerr << "Vamos a " << v << " con costo " << w << " y retraso " << nums[b] << "\n";
            // if(v == b) {
            //     cerr << "si\n";
            // }

            if (d + w * nums[b] < dist[v][b]) {
                pq.erase({dist[v][b], v, b});
                dist[v][b] = d + w * nums[b];
                pq.insert({dist[v][b], v, b});
            }
 
            if (d + w * nums[b] < dist[v][v]) {
                // cerr << "mnmn\n";
                pq.erase({dist[v][v], v, v});
                dist[v][v] = d + w * nums[b];
                pq.insert({dist[v][v], v, v});
            }
        }

        // cerr << "\n\n\n";
    }

    // cerr << "----------------\n";
    // // cout << *min_element(all(dist[n])) << "\n";
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cerr << dist[i][j] << " \n"[j == n];
    //     }
    // }

    cout << dist[n][n] << "\n";
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