#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int n;
    cin >> n;

    vector<tuple<int, int, int>> cows(n);
    for (auto &[x, y, p]: cows) {
        cin >> x >> y >> p;
    }

    auto d_sq = [] (int x1, int y1, int x2, int y2) -> int64_t {
        int64_t dx = x1 - x2;
        int64_t dy = y1 - y2;
        return dx * dx + dy * dy;
    };

    vector<vector<int>> g(n, vector<int>());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }

            auto [x1, y1, p1] = cows[i];
            auto [x2, y2, p2] = cows[j];

            if (d_sq(x1, y1, x2, y2) <= p1 * p1) {
                g[i].push_back(j);
            }
        }
    }

    auto bfs = [&] (int start) -> int {
        vector<int> vis(n);
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        int ans = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v: g[u]) {
                if (vis[v] == 0) {
                    ans++;
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        return ans;
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, bfs(i));
    }

    cout << ans << "\n";


    return 0;
}