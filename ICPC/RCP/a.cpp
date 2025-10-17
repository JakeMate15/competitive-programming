#include <bits/stdc++.h>
using namespace std;

const int N = 1E5 + 10;

int n, m;
int deg[N], vis[N];
vector<int> g[N], v0, v1;

void dfs(int idx, int par, int pa){
    vis[idx] = pa;
    for(int i : g[idx]){
        if(i == pa || i == par){
            continue;
        }
        if(vis[i] == pa) break;
        dfs(i,idx,pa);
        break;
    }
}

bool check2(int s, int pa){
    for(int i = 1; i <= n; i++){
        if(deg[i] > 2) 
            return false;
    }
    dfs(s, 0, pa);
    for(int i = 1; i <= n; i++){
        if(i == pa) 
            continue;
        if(vis[i] != pa){
            // cout << "f2" << "";
            return false;
        }
    }
    return true;
}

bool check(int idx) {
    // cout << "CHECK " << idx << endl;
    int degi = deg[idx];
    deg[idx] = 0;
    for(int i: g[idx]){
        deg[i]--;
    }
    int idx1 = -1;
    for(int i = 1; i <= n; i++){
        if(i == idx) continue;
        if(deg[i] == 1){
            idx1 = i;
            break;
        }
    }
    
    bool ans = false;
    if(idx1 != -1){
        ans = check2(idx1,idx);
    }
    for(int i : g[idx]){
        deg[i]++;
    }
    deg[idx] = degi;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    int sidx = -1;
    for(int i = 1; i <= n; i++){
        if(deg[i] == 0 || deg[i] >= 3){
            sidx = i;
        }
    }

    if(sidx == -1){
        sidx = 1;
        for(int i = 1; i <= n; i++){
            if(deg[i] == 1){
                sidx = i;
            }
        }
        if(check2(sidx, -1)){
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
        return 0;
    }

    if(check(sidx)){
        cout << "yes\n";
        return 0;
    }

    if(deg[sidx] > 3){
        cout << "no\n";
        return 0;
    }

    for(int i : g[sidx]){
        if(check(i)){
            cout << "yes\n";
            return 0;
        }
    }
    
    cout << "no\n";
    return 0;
}