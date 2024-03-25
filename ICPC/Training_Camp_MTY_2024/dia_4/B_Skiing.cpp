#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, ll> pil;

const int MX = 2e5 + 5;
const ll INF = 2e18;

vector<pil> g[MX]; 
vector<ll> d, h; 

ll dijkstra(int s, int n) {
    d.resize(n + 1, INF);
    d[s] = 0;
    set<pil> st;
    st.insert({0, s});
    ll r = 0;

    while (!st.empty()) {
        auto [dist, v] = *st.begin(); 
        st.erase(st.begin());
        if (d[v] < dist) continue;

        for (auto& edge : g[v]) {
            int to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                st.erase({d[to], to});
                d[to] = d[v] + len;
                st.insert({d[to], to});
            }
        }
    }

    for(int i = 2; i <= n; ++i) {
        r = max(r, h[s] - h[i] - d[i]);
    }

    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    h.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        g[u].emplace_back(v, max(0LL, h[v] - h[u]));
        g[v].emplace_back(u, max(0LL, h[u] - h[v]));
    }

    cout << dijkstra(1, n) << "\n";

    return 0;
}
