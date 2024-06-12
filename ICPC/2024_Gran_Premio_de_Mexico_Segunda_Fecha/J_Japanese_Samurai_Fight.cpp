#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

void sol () {
    int n;
    cin >> n;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    // cin >> tt;

    while (tt--) {
        sol();
    }
}   