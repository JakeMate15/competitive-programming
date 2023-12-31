#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

vector<vector<pair<int, ll>>> g;
const ll INF = LONG_LONG_MAX;
vector<ll> d;
vector<int> p;

void dijkstra(int s) {
    int n = g.size();
    d.assign(n, INF);
    p.assign(n, 0);

    d[s] = 0;
    set<pair<ll, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : g[v]) {
            int to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}

// Camino mas cortes de s a t
vector<int> restore_path(int s, int t) {
    vector<int> res = {t};

    while(p[t]) {
        res.push_back(p[t]);
        t = p[t];
    }

    reverse(all(res));
    return (t == s ? res : vector<int>());
}

void sol(){
    int n, m;
    cin >> n >> m;

    g.resize(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
    }

    dijkstra(1);
    for(int i = 1; i <= n; i++) 
        cout << d[i] << " \n"[i == n];

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}