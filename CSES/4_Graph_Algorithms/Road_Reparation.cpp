#include<bits/stdc++.h>
using namespace std;
 
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
 
typedef long long ll;
typedef long double ld;

struct DSU {
    vector<int> par;
    vector<int> rank; // rank[x] = size of the component where x belongs
    int tam;
 
    DSU(int n) {
        par.resize(n + 1);
        rank.resize(n + 1);
        tam = n - 1;
        for (int i = 1; i <= n; i++) {
            par[i] = i;
            rank[i] = 1;
        }
    }
 
    int find(int x) {
        if (par[x] == x) {
            return x;
        } 
        else {
            return (par[x] = find(par[x])); // Path Compression
        }
    }
 
    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty) {
            // both elements are in the same component
            return;
        }
        if (rank[rootx] < rank[rooty]) { // Rank Compression
            swap(rootx, rooty);
        }
        rank[rootx] += rank[rooty];
        par[rooty] = rootx;
        tam--;
    }

    bool same(int u, int v){
        return find(u) == find(v);
    }
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> g(m);
    for (auto &[w, u, v]: g) {
        cin >> u >> v >> w;
    }

    sort(all(g));
    DSU ds(n + 1);
    ll res = 0;

    for (auto &[w, u, v]: g) {
        if (!ds.same(u, v)) {
            res += w;
            ds.unite(u, v);
        }
    }

    if (ds.tam != 2) 
        cout << "IMPOSSIBLE";
    else
        cout << res;

    return 0;
}