#include<bits/stdc++.h>
using namespace std;
 
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";
 
typedef long long ll;
typedef long double ld;
 
const int mod = 1e9 + 7;
const int MX = 2e5 + 5;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> g(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    vector<int> colores(n + 1, -1);
    for(int i = 1; i <= n; i++) {
        if(colores[i] != -1) 
            continue;
 
        queue<int> q;
        q.push(i);
        colores[i] = 0;
        while(!q.empty()) {
            int nodo = q.front();
            q.pop();
 
            for(auto u: g[nodo]) {
                if(colores[u] == -1) {
                    colores[u] = colores[nodo] ^ 1;
                    q.push(u);
                }   
                else if(colores[u] ==  colores[nodo]) {
                    cout << "IMPOSSIBLE\n";
                    return 0;
                }
            }
        }
    }
 
    for(int i = 1; i <= n; i++) {
        cout << colores[i] + 1 << " \n"[i == n];
    }
    return 0;
}