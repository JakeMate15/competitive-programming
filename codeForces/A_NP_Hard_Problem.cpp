#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

vector<vector<int>> graph;
vector<int> side;
 
bool isBipartite(int n){
    bool isBipartite = true;
    side.resize(n + 1, -1);
    queue<int> q;
    for(int st = 0; st<=n; st++){
        if(side[st] != -1) continue;
        q.push(st);
        side[st] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : graph[u]){
                if(side[v] == -1){
                    q.push(v);
                    side[v] = side[u]^1;
                } else {
                    isBipartite &= side[v] != side[u];
                }
            }
        }
    }
    return isBipartite;
}
 

void sol(){
    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);

    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if(!isBipartite(n)) {
        cout << -1 << "\n";
    }
    else{
        
        vector<int> c1, c2;
        for(int i = 1; i <= n; i++) {
            if(side[i] == 0) {
                c1.push_back(i);
            }
            else if(side[i] == 1) {
                c2.push_back(i);
            }
        }

        cout << sz(c1) << "\n";
        for(auto x: c1) {
            cout << x << "\n";
        }
        nl;

        cout << sz(c2) << "\n";
        for(auto x: c2) {
            cout << x << "\n";
        }
        nl;
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