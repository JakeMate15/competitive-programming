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
const ll INF = LONG_LONG_MAX / 2;

void dijkstra(int s, vector<ll> &d, vector<int> &bicicletas) {
    int n = g.size();
    d.assign(n, INF);
    ll mn = bicicletas[s];

    d[s] = 0;
    set<pair<ll, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        mn = min(mn, 1LL * bicicletas[v]);

        for (auto edge : g[v]) {
            int to = edge.first;
            ll len = edge.second * mn;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }
    }
}

void dijkstra2(int s, vector<ll> &d, vector<int> &bicicletas) {
    int n = g.size();
    d.assign(n, INF);
    ll mn = bicicletas[s];

    d[s] = 0;
    set<pair<ll, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        if(v == 1)
            continue;
        mn = min(mn, 1LL * bicicletas[v]);

        for (auto edge : g[v]) {
            int to = edge.first;
            ll len = edge.second * mn;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }
    }
}


void sol(){
    int n, m;
    cin >> n >> m;
    
    g.clear();
    g.resize(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    vector<int> bicicletas(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> bicicletas[i];
    }

    vector<ll> d1(n + 1), d2(n + 1);
    dijkstra(1, d1, bicicletas);
    ll res = d1[n];
    // cerr << "=============\n";
    // for(int i = 1; i <= n; i++) {
    //     cerr << d1[i] << " \n"[i == n];
    // }
    for(int i = 1; i < n; i++) {
        dijkstra2(i, d2, bicicletas);
        res = min(res, d1[i] + d2[n]);
        // for(int j = 1; j <= n; j++) {
        //     cerr << d2[j] << " \n"[j == n];
        // }
    }

    cout << res << "\n";

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}