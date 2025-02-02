#include<bits/stdc++.h>
using namespace std;

#define sz(a)       (int) a.size()
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int MX = 2E5 + 5;
const int MOD = 1E9 + 7;

template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

void sol () {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<int> g[n + 1], inDeg(n + 1), vis(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
    
        g[u].push_back(v);
        inDeg[v]++;
    }

    pqg<ii> pq;
    for (int i = 1; i <= n; i++) {
        if (inDeg[i] == 0) {
            pq.emplace(arr[i], i);
            vis[i] = true;
        }
    }

    vector<int> ans;
    while (!pq.empty()) {
        auto [gr, u] = pq.top();
        pq.pop();
        ans.push_back(u);

        for (auto v: g[u]) {
            inDeg[v]--;
            if (inDeg[v] <= 0 && !vis[v]) {
                pq.emplace(arr[v], v);
                vis[v] = true;
            }
        }
    }

    if (sz(ans) != n) {
        cout << -1 << "\n";
        return;
    }

    for (auto &x: ans) {
        cout << x << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    // cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}