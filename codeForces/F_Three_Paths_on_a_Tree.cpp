#include<bits/stdc++.h>
using namespace std;

template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> g(n + 1);
    vector<array<int, 3>> aux(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto dfs = y_combinator([&](auto dfs, int u, int p, int h, bool f = false) -> pair<int, int> {
        pair<int, int> best = {u, h};
        for (auto v: g[u]) {
            if (v != p) {
                auto[who, maxH] = dfs(v, u, h + 1, f);
                if (maxH > best.second) {
                    best.first = who;
                    best.second = maxH; 
                }
            }
        }
        if (f) {
            aux[u][0] = u;
            aux[u][1] = best.first;
            aux[u][2] = best.second;
        }
        return best;
    });

    int a, b, c = 0, _;
    tie(a, _) = dfs(1, 0, 0);
    tie(b, _) = dfs(a, 0, 0, true);

    queue<int> q;
    vector<int> dis(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (aux[i][1] == b) {
            q.push(aux[i][0]);
            dis[aux[i][0]] = 0;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v: g[u]) {
            if (dis[v] == -1) {
                q.push(v);
                dis[v] = dis[u] + 1;
            } 
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dis[i] > dis[c] && i != b && i != a) {
            c = i;
        }
    }

    cout << _ + dis[c] << "\n";
    cout << a << " " << b << " " << c << "\n";

    return 0;
}