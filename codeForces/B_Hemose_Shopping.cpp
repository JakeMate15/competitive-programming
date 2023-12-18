#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

struct DSU {
    vector<int> par;
    vector<int> rank; // rank[x] = size of the component where x belongs
 
    DSU(int n) {
        par.resize(n + 1);
        rank.resize(n + 1);
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
    }

    bool same(int u, int v){
        return find(u) == find(v);
    }
};

void sol(){
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}