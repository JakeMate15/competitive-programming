#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...)
#endif

// Compresion y balanceo

struct DSU {
    vector<int> par;
    vector<int> rank;
    int tam;
 
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
 
    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty) {
            return;
        }
        if (rank[rootx] < rank[rooty]) {
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

void sol () {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> colores(11, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        int a, d, k;
        cin >> a >> d >> k;

        colores[d][a]++;
        colores[d][a + d * k]--;
    }

    DSU ds(n);
    for (int d = 1; d <= 10; d++) {
        for (int i = 1; i <= n; i++) {
            colores[d][i] += colores[d][max(0, i - d)];

            if (colores[d][max(0, i - d)] > 0 && i - d > 0) {
                ds.unite(i, i - d);
            }
        }
    }

    cout << ds.tam << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}