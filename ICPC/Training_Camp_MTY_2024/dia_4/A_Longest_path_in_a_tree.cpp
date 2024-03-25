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

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

vvi g;

void dfs(int nodo, int padre, vector<ll> &dist) {
    dist[nodo] = dist[padre] + 1;

    for (auto u: g[nodo]) {
        if (u != padre) {
            dfs(u, nodo, dist);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    g.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }


    vector<ll> d1(n+ 1), res(n + 1);
    d1[0] = -1, res[0] = -1;
    dfs(1, 0, d1);

    int mx = max_element(all(d1)) - d1.begin();
    dfs(mx, 0, res);
    cout << *max_element(all(res)) << "\n";


    return 0;
}