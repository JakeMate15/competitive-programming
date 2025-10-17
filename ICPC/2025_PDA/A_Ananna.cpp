#include<bits/stdc++.h>
using namespace std;
 
typedef pair<int, char> edge;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<edge>> out(n + 1), in(n + 1);
    for (int i = 0; i < m; i++){
        int u, v;
        char c;
        cin >> u >> v >> c;
        out[u].emplace_back(v, c);
        in[v].emplace_back(u, c);
    }

    int t = (n + 1) * (n + 1);
    vector<char> vis(t, 0), va(t, 0);
    auto idx = [&](int u, int v) -> int {
        return u * (n + 1) + v;
    };

    queue<pair<int, int>> q;
    for (int u = 1; u <= n; u++){
        int i = idx(u, u);
        vis[i] = 1;
        q.emplace(u, u);
    }

    for (int u = 1; u <= n; u++){
        for(auto &e : out[u]){
            int v = e.first;
            int i = idx(u, v);
            if(!vis[i]){
                vis[i] = 1;
                va[i] = 1;
                q.emplace(u, v);
            } else {
                va[i] = 1;
            }
        }
    }

    while(!q.empty()){
        auto [u, v] = q.front();
        q.pop();
        for(auto &inE : in[u]){
            for(auto &outE : out[v]){
                if(inE.second == outE.second){
                    int u2 = inE.first, v2 = outE.first;
                    int nI = idx(u2, v2);
                    if(!vis[nI]){
                        vis[nI] = 1;
                        va[nI] = 1;
                        q.push({u2, v2});
                    } else if(!va[nI]){
                        va[nI] = 1;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int u = 1; u <= n; u++){
        for (int v = 1; v <= n; v++){
            if(u != v && va[idx(u, v)])
                ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
