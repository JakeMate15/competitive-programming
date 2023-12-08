#include<bits/stdc++.h>
using namespace std;

void sol(){
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n + 1);
    vector<vector<int>> res(n + 1, vector<int>(n + 1, 1e9));
    vector<int> distancia(n + 1);
    
    for (int i = 0; i < m; i++) {
        int u, v, peso;
        cin >> u >> v >> peso;
        
        g[0].emplace_back(u, v);
        g[u].emplace_back(v, peso);
        g[v].emplace_back(u, peso);
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 1; k <= n; k++) {
                fill(distancia.begin(), distancia.end(), 1e9);
                distancia[k] = 0;
                
                priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
                for (auto [v, peso] : g[k]) {
                    if ((j ? ~v : v) & (1 << i)) {
                        q.push({distancia[v] = peso, v});
                    }
                }
                
                while (!q.empty()) {
                    auto [d, u] = q.top();
                    q.pop();
                    
                    if (d != distancia[u]) {
                        continue;
                    }
                    
                    for (auto [v, peso] : g[u]) {
                        if (d + peso < distancia[v]) {
                            q.push({distancia[v] = d + peso, v});
                        }
                    }
                }
                
                for (auto [v, peso] : g[k]) {
                    if ((j ? v : ~v) & (1 << i)) {
                        res[k][v] = min(res[k][v], distancia[v]);
                    }
                }
            }
        }
    }
    
    for (auto [u, v] : g[0]) {
        if (res[u][v] == 1e9) {
            cout << -1 << '\n';
        } 
        else {
            cout << res[u][v] << '\n';
        }
    }  
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t=1;
    //cin>>t;

    while(t--){
        sol();
    }

    return 0;
}

