#include <bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()
#define sz(a)   (int) a.size()

typedef long long ll;
typedef pair<int, int> ii;
    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    set<int> nv;
    vector<set<int>> adj(n + 1);
    vector<int> comp(n + 1), tam(n + 1);

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        adj[x].insert(y);
        adj[y].insert(x);
    }

    for(int i = 1; i <= n; i++) {
        nv.insert(i);
    }
    
    auto bfs = [&] (int s, int c) {
        queue<int> q({s});
        comp[s] = c;
        tam[c]++;

        while(!q.empty()) {
            int u = q.front(); 
            q.pop();

            vector<int> vis;
            for(auto x : nv) {
                if(adj[u].count(x) || comp[x])
                    continue;
                comp[x] = c;
                tam[c]++;
                vis.push_back(x);
                q.push(x);
            }
            for(auto x : vis)
                nv.erase(x); 
            vis.clear();
        }
    };
    
    int cc = 0;
    for(int i = 1; i <= n; i++) {
        if(!comp[i]) {
            cc++;
            bfs(i, cc);
        }
    }
    cout << cc - 1 << '\n';
}