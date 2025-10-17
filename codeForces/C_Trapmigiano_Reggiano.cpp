#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "/algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

#define sz(a)       (int) a.size()
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()

const int MX = 2E5 + 5;
const int MOD = 1E9 + 7;

void sol () {
    int n, st, en; 
    cin >> n >> st >> en;

    vector<vector<int>> g(n + 1);
    for(int i = 1; i < n; i++){
        int u, v; 
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[en] = 0;
    q.push(en);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : g[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    vector<int> p(n);
    for(int i = 0; i < n; i++){
        p[i] = i + 1;
    }

    sort(p.begin(), p.end(), [&](int a, int b){
        return dist[a] > dist[b];
    });

    for(auto v : p)
        cout << v << " ";
    cout << "\n";
    
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