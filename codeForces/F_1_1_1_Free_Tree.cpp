#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()

typedef vector<pair<int, int>> T;

void sol () {
    int n, q; 
    cin >> n >> q;

    vector<int> col(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> col[i];
    }

    int64_t sp = 0;  
    vector<T> g(n + 1);
    vector<tuple<int, int, int>> edg;
    for(int i = 0, u, v, c; i < n - 1; i++){
        cin >> u >> v >> c;
        g[u].emplace_back(v,c);
        g[v].emplace_back(u,c);
        edg.emplace_back(u,v,c);
        sp += c;
    }

    int B = 450;
    vector<bool> esP(n + 1);
    for(int i = 1; i <= n; i++) {
        if(g[i].size() > B) 
            esP[i] = true;
    }

    vector<T> vecP(n + 1);
    for(int i = 1; i <= n; i++) {
        for(auto &p : g[i])
            if(esP[p.first])
                vecP[i].emplace_back(p);
    }

    vector<map<int, int64_t>> mp(n + 1);
    for(int i = 1; i <= n; i++) {
        if(esP[i]) {
            for(auto &p : g[i])
                mp[i][col[p.first]] += p.second;
        }
    }

    int64_t ig = 0;
    for(auto &[u, v, c] : edg){
        if(col[u] == col[v]) 
            ig += c;
    }

    int64_t res = sp - ig;
    while(q--){
        int v, x; 
        cin >> v >> x;

        if(col[v] != x){
            int64_t vo = 0, ne = 0;
            if(esP[v]){
                auto &m = mp[v];
                if(m.count(col[v])) 
                    vo = m[col[v]];
                if(m.count(x))      
                    ne = m[x];
            } else {
                for(auto &[a, b] : g[v]){
                    if(col[a] == col[v]) 
                        vo += b;
                    if(col[a] == x)      
                        ne += b;
                }
            }
            ig -= vo; ig += ne;
            for(auto &[u, c] : vecP[v]){
                auto &m = mp[u];
                m[col[v]] -= c;
                if(m[col[v]] == 0) 
                    m.erase(col[v]);
                m[x] += c;
            }
            col[v] = x;
            res = sp - ig;
        }
        cout << res << "\n";
    }
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