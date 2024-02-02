#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

struct two_sat {
    int n;
    vector<vector<int>> g, gr; // gr is the reversed graph
    vector<int> comp, topological_order, answer; // comp[v]: ID of the SCC containing node v
    vector<bool> vis;

    two_sat() {}

    two_sat(int _n) { init(_n); }

    void init(int _n) {
        n = _n;
        g.assign(2 * n, vector<int>());
        gr.assign(2 * n, vector<int>());
        comp.resize(2 * n);
        vis.resize(2 * n);
        answer.resize(2 * n);
    }

    void add_edge(int u, int v) {
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    void add_edge(int i, bool f, int j, bool g) {
        add_edge(i + (f ? 0 : n), j + (g ? 0 : n));
        add_edge(j + (g ? n : 0), i + (f ? n : 0));
    }

    // For the following three functions
    // int x, bool val: if 'val' is true, we take the variable to be x. Otherwise we take it to be x's complement.

    // At least one of them is true
    void add_clause_or(int i, bool f, int j, bool g) {
        add_edge(i + (f ? n : 0), j + (g ? 0 : n));
        add_edge(j + (g ? n : 0), i + (f ? 0 : n));
    }

    // Only one of them is true
    void add_clause_xor(int i, bool f, int j, bool g) {
        add_clause_or(i, f, j, g);
        add_clause_or(i, !f, j, !g);
    }

    // Both of them have the same value
    void add_clause_and(int i, bool f, int j, bool g) {
        add_clause_xor(i, !f, j, g);
    }

    void add_clause_either(int i, bool fi, int j, bool fj) {
        add_edge(i + (fi ? 0 : n), j + (fj ? n : 0));
        add_edge(j + (fj ? 0 : n), i + (fi ? n : 0));
    }

    // Topological sort
    void dfs(int u) {
        vis[u] = true;

        for (const auto &v : g[u])
            if (!vis[v]) dfs(v);

        topological_order.push_back(u);
    }

    // Extracting strongly connected components
    void scc(int u, int id) {
        vis[u] = true;
        comp[u] = id;

        for (const auto &v : gr[u])
            if (!vis[v]) scc(v, id);
    }

    // Returns true if the given proposition is satisfiable and constructs a valid assignment
    bool satisfiable() {
        fill(vis.begin(), vis.end(), false);

        for (int i = 0; i < 2 * n; i++)
            if (!vis[i]) dfs(i);

        fill(vis.begin(), vis.end(), false);
        reverse(topological_order.begin(), topological_order.end());

        int id = 0;
        for (const auto &v : topological_order)
            if (!vis[v]) scc(v, id++);

        // Constructing the answer
        for (int i = 0; i < n; i++) {
            if (comp[i] == comp[i + n]) return false;
            answer[i] = (comp[i] > comp[i + n] ? 1 : 0);
        }

        return true;
    }
};

void sol(){
    int n, m;
    cin >> n >> m;
    
    two_sat ts(n);
    
    for (int i = 0; i < m; i++) {
        int x, y, k;
        string op;
        cin >> x >> y >> op >> k;
        for (int a = 0; a <= 1; a++) {
            for (int b = 0; b <= 1; b++) {
                bool bueno = false;
                if (op == "=" && a+b == k) bueno = true;
                if (op == "!=" && a+b != k) bueno = true;
                if (op == "<" && a+b < k) bueno = true;
                if (op == ">" && a+b > k) bueno = true;
                if (op == "<=" && a+b <= k) bueno = true;
                if (op == ">=" && a+b >= k) bueno = true;
                if (!bueno) {
                    ts.add_clause_either(x, a, y, b);
                }
            }
        }
    }

    cout << (ts.satisfiable() ? "Yes" : "No") << "\n";

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;

    while(t--){
        sol();
    }

    return 0;
}