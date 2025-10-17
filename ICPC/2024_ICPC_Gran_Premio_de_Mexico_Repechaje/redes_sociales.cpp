#include <iostream>
#include <vector>
using namespace std;

struct DSU {
    vector<int> parent;
    DSU(int n) : parent(n) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int a) {
        return parent[a] == a ? a : parent[a] = find(parent[a]);
    }
    void merge(int a, int b) {
        a = find(a), b = find(b);
        if(a != b) parent[b] = a;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<long long> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    DSU dsu(n);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        dsu.merge(u - 1, v - 1);
    }
    int root = dsu.find(0);
    for (int i = 1; i < n; i++){
        if(dsu.find(i) != root){
            for (int j = 0; j < n; j++) cout << "0";
            return 0;
        }
    }
    long long mx = 0;
    for (int i = 0; i < n; i++){
        if(h[i] > mx) mx = h[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if(h[i] == mx) cnt++;
    }
    for (int i = 0; i < n; i++){
        if(h[i] == mx && cnt == 1) cout << "1";
        else cout << "0";
    }
    return 0;
}
