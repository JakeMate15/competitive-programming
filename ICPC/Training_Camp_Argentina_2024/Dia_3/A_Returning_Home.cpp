#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()
#define sz(a)   (int) a.size()

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<vector<ll>> vvi;

const ll mx = 1E5 + 5;

int main () {
    ll m, n;
    cin >> m >> n;

    ii s, f;
    vector<ll> t(mx);
    vector<bool> vis(mx);
    vvi g(mx, vector<ll>());
    vector<ii> nodos(mx), x(mx), y(mx);

    cin >> s.first >> s.second;
    cin >> f.first >> f.second;

    for (int i = 0; i < n; i++) {
        cin >> nodos[i].first >> nodos[i].second;
        x[i].first = nodos[i].first;
        x[i].second = i;
        y[i].first = nodos[i].second;
        y[i].second = i;
    }

    sort(all(x));
    sort(all(y));

    ii aux;
    for (int i = 0; i < n; i++) {
        aux.first = nodos[i].first;
        aux.second = i;

        int pos = upper_bound(all(x), aux) - x.begin();
        if (pos != n) {
            // cerr << x[pos].second << "\n";
            g[x[pos].second].push_back(i);
            g[i].push_back(x[pos].second);
        }

        aux.first = nodos[i].second;
        aux.second = i;

        pos = upper_bound(all(y), aux) - y.begin();
        if (pos != n) {
            g[y[pos].second].push_back(i);
            g[i].push_back(y[pos].second);
        }
    }

    priority_queue<ii> pq;
    for (int i = 0; i < n; i++) {
        t[i] = min(abs(nodos[i].first - s.first), abs(nodos[i].second - s.second));
        pq.emplace(-t[i], i);
    }

    ll nc, res = abs(s.first - f.first) + abs(s.second - f.second);
    while (!pq.empty()) {
        ll u = pq.top().second;
        pq.pop();

        if (vis[u]) {
            continue;
        }

        res = min(res, t[u] + abs(nodos[u].first - f.first) + abs(nodos[u].second - f.second));
        vis[u] = true;
        for (auto v: g[u]) {
            nc = t[u] + min(abs(nodos[u].first - nodos[v].first), abs(nodos[u].second - nodos[v].second));
            if (nc >= t[v]) {
                // cerr << nc << " " << t[v] << "\n";
                continue;
            }
            t[v] = nc;
            pq.emplace(-t[v], v);
        }
    }

    cout << res << "\n";

    return 0;
}