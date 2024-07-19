#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<ii> parejas;
    vector<vector<int>> adj(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
        parejas.emplace_back(u, v);
    }

    vector<int> color(n + 1, -1);
    bool bip = true;
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (color[i] == -1) {
            q.push(i);
            color[i] = 0;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int u : adj[v]) {
                    if (color[u] == -1) {
                        color[u] = color[v] ^ 1;
                        q.push(u);
                    } else {
                        bip &= color[u] != color[v];
                    }
                }
            }
        }
    }

    if (!bip) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for (auto [u, v]: parejas) {
        if (color[u] == 0) {
            cout << "1";
        }
        else {
            cout << "0";
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << color[i];
    // }

    return 0;
}