#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> best(n + 2, 0);
    for (int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        best[l] = max(best[l], r);
    }

    for (int i = 1; i <= n; i++){
        best[i] = max(best[i], best[i - 1]);
    }

    for (int i = 0; i < q; i++){
        int u, v;
        cin >> u >> v;
        if(u > v) swap(u, v);
        cout << (best[u] >= v ? "Yes" : "No") << "\n";
    }
    
    return 0;
}
