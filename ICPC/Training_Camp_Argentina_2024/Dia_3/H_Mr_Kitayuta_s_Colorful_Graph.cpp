#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

struct DSU {
    vector<int> par;
    vector<int> rank; 
    int tam, n = 105;
 
    DSU() {
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
 
    void unite(int x, int y) {
        int rootx = find(x), rooty = find(y);
        if (rootx == rooty) 
            return;
        if (rank[rootx] < rank[rooty])
            swap(rootx, rooty);
        rank[rootx] += rank[rooty];
        par[rooty] = rootx;
        tam--;
    }

    bool same(int u, int v){
        return find(u) == find(v);
    }
};

int main () {
    int n, m;
    cin >> n >> m;

    map<int, DSU> mp;
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;

        mp[c].unite(u, v);
    }

    int q;
    cin >> q;

    while (q--) {
        int u, v;
        cin >> u >> v;

        int res = 0;
        for (auto [k, ds]: mp) {
            res += ds.same(u, v);
        }

        cout << res << "\n";
    }
}