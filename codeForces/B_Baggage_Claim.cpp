#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> odd(2*k+1);
        for(int i = 0; i < k+1; i++){
            int x, y;
            cin >> x >> y;
            odd[i] = (x-1)*m + (y-1);
        }
        int N = n*m;
        vector<int> opt1(k), opt2(k), sc(k);
        bool bad = false;
        for(int i = 0; i < k; i++){
            int a = odd[i], c = odd[i+1];
            int x1 = a / m, y1 = a % m;
            int x2 = c / m, y2 = c % m;
            int dx = abs(x1 - x2), dy = abs(y1 - y2);
            if(dx + dy != 2){
                bad = true;
                break;
            }
            if(dx == 2){
                int xm = (x1 + x2) / 2;
                opt1[i] = xm*m + y1;
                sc[i] = 1;
            } else if(dy == 2){
                int ym = (y1 + y2) / 2;
                opt1[i] = x1*m + ym;
                sc[i] = 1;
            } else {
                opt1[i] = x1*m + y2;
                opt2[i] = x2*m + y1;
                sc[i] = 2;
            }
        }
        if(bad){
            cout << 0 << "\n";
            continue;
        }
        vector<vector<int>> cell2seg(N);
        for(int i = 0; i < k; i++){
            if(sc[i] >= 1) cell2seg[opt1[i]].push_back(i);
            if(sc[i] == 2) cell2seg[opt2[i]].push_back(i);
        }
        vector<char> used(N, 0), proc(k, 0);
        deque<int> q;
        for(int i = 0; i < k; i++){
            if(sc[i] == 1) q.push_back(i);
        }
        bool zero = false;
        while(!q.empty()){
            int i = q.front(); q.pop_front();
            if(proc[i] || sc[i] != 1) continue;
            int u = opt1[i];
            if(used[u]){
                zero = true;
                break;
            }
            used[u] = 1;
            proc[i] = 1;
            for(int j: cell2seg[u]){
                if(proc[j]) continue;
                if(sc[j] == 2){
                    int v = (opt1[j] == u ? opt2[j] : opt1[j]);
                    opt1[j] = v;
                    sc[j] = 1;
                    q.push_back(j);
                }
            }
        }
        if(zero){
            cout << 0 << "\n";
            continue;
        }
        vector<pair<int,int>> edges;
        vector<int> cells;
        vector<char> active(N, 0);
        for(int i = 0; i < k; i++){
            if(proc[i]) continue;
            if(sc[i] != 2){
                zero = true; break;
            }
            int u = opt1[i], v = opt2[i];
            if(used[u] || used[v]){
                zero = true;
                break;
            }
            edges.emplace_back(u, v);
            if(!active[u]){
                active[u] = 1;
                cells.push_back(u);
            }
            if(!active[v]){
                active[v] = 1;
                cells.push_back(v);
            }
        }
        if(zero){
            cout << 0 << "\n";
            continue;
        }
        sort(cells.begin(), cells.end());
        int nc = cells.size();
        vector<int> mp(N, -1);
        for(int i = 0; i < nc; i++){
            mp[cells[i]] = i;
        }
        vector<vector<int>> adj(nc);
        for(auto &e: edges){
            int u = mp[e.first], v = mp[e.second];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<char> vis(nc, 0);
        ll ans = 1;
        for(int i = 0; i < nc; i++){
            if(vis[i]) continue;
            ll vc = 0, de2 = 0;
            deque<int> dq;
            dq.push_back(i);
            vis[i] = 1;
            while(!dq.empty()){
                int u = dq.front(); dq.pop_front();
                vc++;
                de2 += adj[u].size();
                for(int w: adj[u]){
                    if(!vis[w]){
                        vis[w] = 1;
                        dq.push_back(w);
                    }
                }
            }
            ll ec = de2 / 2;
            if(ec == vc - 1){
                ans = ans * vc % MOD;
            } else if(ec == vc){
                ans = ans * 2 % MOD;
            } else {
                ans = 0;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
