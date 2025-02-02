#include<bits/stdc++.h>
using namespace std;

const int64_t MOD = 1E9 + 7;

struct DSU {
    vector<int> par;
    vector<int> rank;
    int tam;
    int64_t res = 0;
 
    DSU(int n) {
        par.resize(n + 1);
        rank.resize(n + 1);
        tam = n;
        for (int i = 1; i <= n; i++) {
            par[i] = i;
            rank[i] = 1;
        }
    }
 
    int find(int x) {
        return (par[x] == x ? x : par[x] = find(par[x]));
    }
 
    void unite(int x, int y, int64_t w) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty)
            return;
        if (rank[rootx] < rank[rooty])
            swap(rootx, rooty);

        res += w * rank[rootx] * rank[rooty] % MOD;

        rank[rootx] += rank[rooty];
        par[rooty] = rootx;
        tam--;
    }

    bool same(int u, int v){
        return find(u) == find(v);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<tuple<int, int, int>> arr(n - 1);
    for (auto &[w, u, v]: arr) {
        cin >> u >> v >> w;
    }

    sort(arr.begin(), arr.end());

    DSU ds(n);
    for (auto [w, u, v]: arr) {
        ds.unite(u, v, w);
    }

    cout << ds.res << "\n";

    return 0;
}