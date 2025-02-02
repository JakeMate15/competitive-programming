#include<bits/stdc++.h>
using namespace std;

struct LCA {
    int N;
    int root;
    vector<int> st;
    vector<int> tin;
    vector<int> depth;
    vector<int> euler;
    vector<vector<int>> tree;

    LCA (int n, int _root) : root(_root) {
        tin.resize(n);
        tree.resize(n);
    }

    void run () {
        dfs(root, -1, 0);
        N = euler.size();
        ST();
    }

    void addEdge (int u, int v) {
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    void dfs (int u, int p, int d) {
        tin[u] = euler.size();
        depth.push_back(d);
        euler.push_back(u);
        for (auto v: tree[u]) {
            if (v != p) {
                dfs(v, u, d + 1);
                depth.push_back(d);
                euler.push_back(u);
            }
        }
    }

    int merge(int x, int y) {
        return depth[x] < depth[y] ? x : y;
    }

    void ST () {
        st.resize(N << 1);
        for (int i = 0; i < N; i++)
            st[N + i] = i; 
        for (int i = N - 1; i > 0; i--) 
            st[i] = merge(st[i << 1], st[i << 1 | 1]);
    }

    int lca (int u, int v) {
        u = tin[u], v = tin[v];
        if (v < u) swap(u, v);
        int ans = u;
        for (u += N, v += N; u <= v; u >>= 1, v >>= 1) {
            if (u & 1)      ans = merge(ans, st[u++]);
            if (!(v & 1))   ans = merge(ans, st[v--]);
        }
        return euler[ans];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;

    LCA lca(n, 0);
    for (int i = 1; i < n; i++) {
        int v;
        cin >> v;
        lca.addEdge(i, v - 1);
    }

    lca.run();

    while (q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        cout << lca.lca(u, v) + 1 << "\n";
    }

    return 0;
}