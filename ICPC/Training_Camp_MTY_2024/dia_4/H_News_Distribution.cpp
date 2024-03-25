#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

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
        if (par[x] == x) {
            return x;
        } 
        else {
            return (par[x] = find(par[x])); 
        }
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    DSU ds(n);
    for(int i = 0; i < m; i++) {
        int k;
        cin >> k;
        if(k == 0) continue;
        int x;
        cin >> x;
        for(int j = 0; j < k - 1; j++) {
            int y;
            cin >> y;
            ds.unite(x, y);
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << ds.rank[ds.find(i)] << " \n"[i == n];
    }


    return 0;
}

