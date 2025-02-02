#include <bits/stdc++.h>
using namespace std;

template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(ref(*this), forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<decay_t<Fun>>(forward<Fun>(fun)); }

typedef unsigned long long ull;

int main() {
    int n;
    cin >> n;
    vector<int> g[61];
    vector<ull> x(61);
    vector<int> criba;
    set<int> vis;

    vector<int> degree(n + 1, 0);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    x[1] = 1;
    set<int> visP;

    int max_depth = 0;
    vector<int> depth(n + 1, -1);
    vector<int> stack = {1};
    depth[1] = 0;
    while (!stack.empty()) {
        int u = stack.back(); 
        stack.pop_back();
        max_depth = max(max_depth, depth[u]);
        for (int v : g[u]) {
            if (depth[v] == -1) {
                depth[v] = depth[u] + 1;
                stack.push_back(v);
            }
        }
    }

    int N = max_depth + n;
    auto CRIBA = [&](int n) {
        int num = 2;
        while ((int)criba.size() < n) {
            bool is_prime = true;
            for (int i = 2; i * i <= num && is_prime; ++i) {
                if (num % i == 0) {
                    is_prime = false;
                }
            }
            if (is_prime) {
                criba.push_back(num);
            }
            ++num;
        }
    };
    CRIBA(N);

    auto dfs = y_combinator([&](auto self, int u, ull label, set<int>& visP) -> void {
        x[u] = label;
        int idx = 0;
        for (int v : g[u]) {
            if (x[v] != 0) {
                continue;
            }
            while (idx < (int)criba.size() && (visP.count(criba[idx]) || vis.count(criba[idx]))) {
                ++idx;
            }
            assert (idx != (int)criba.size());
            int p = criba[idx];
            visP.insert(p);
            vis.insert(p);
            assert(label <= ULLONG_MAX / p);
            self(v, label * p, visP);
            visP.erase(p);
        }
    });

    dfs(1, 1, visP);

    for (int i = 1; i <= n; ++i) {
        cout << x[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}
