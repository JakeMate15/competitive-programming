#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

#define sz(a)       (int) a.size()
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int MX = 2E5 + 5;
const int MOD = 1E9 + 7;

void sol () {
    int n;
    cin >> n;

    vector<int> deg(n + 5, 0);
    vector<vector<int>> g(n + 5);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    ll ms = -1E9;
    function<ll(int, int)> dfs = [&](int u, int p) -> ll {
        ll cur = deg[u] - 2;
        ll t1 = 0, t2 = 0;
        for(auto &v: g[u]){
            if(v != p){
                ll hijo = dfs(v, u);
                hijo = max(hijo, 0LL);
                if(hijo > t1){
                    t2 = t1;
                    t1 = hijo;
                } else if(hijo > t2){
                    t2 = hijo;
                }
            }
        }
        ll s = cur + t1 + t2;
        ms = max(ms, s);
        return max(cur + t1, cur);
    };
    
    dfs(1, 0);
    cout << ms + 2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}