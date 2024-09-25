#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct info {
    ll nodo, donde, tiempo;

    info(ll nodo, ll donde, ll tiempo) {
        this->nodo = nodo;
        this->donde = donde;
        this->tiempo = tiempo;
    }

    bool operator<(const info& other) const {
        return tiempo > other.tiempo;
    }
};

const ll INF = 1E15;
vector<vector<pair<ll, ll>>> g;
void dijkstra(ll inicio, const set<ll> &st, vector<ll>& dC, vector<ll>& dM, ll n) {
    dC.assign(n + 1, INF);
    dM.assign(n + 1, INF);
    
    priority_queue<info> pq;
    dC[inicio] = 0;
    pq.push(info{inicio, 0, 0});

    while (!pq.empty()) {
        info curr = pq.top();
        pq.pop();

        ll u = curr.nodo;
        ll donde = curr.donde;
        ll currT = curr.tiempo;

        if ((donde == 0 && currT > dC[u]) || (donde == 1 && currT > dM[u])) 
            continue;

        for (auto &[v, w] : g[u]) {
            if (donde == 0) {
                if (currT + w < dC[v]) {
                    dC[v] = currT + w;
                    pq.emplace(v, 0, dC[v]);
                }

                if (st.count(u)) {
                    ll mont = currT + (w / 2);
                    if (mont < dM[v]) {
                        dM[v] = mont;
                        pq.emplace(v, 1, dM[v]);
                    }
                }
            }
            if (donde == 1) {
                ll mont = currT + (w / 2);
                if (mont < dM[v]) {
                    dM[v] = mont;
                    pq.emplace(v, 1, dM[v]);
                }
            }
        }
    }
}

void sol () {
    ll n, m, h;
    cin >> n >> m >> h;

    set<ll> st;
    for(ll i = 0; i < h; i++){
        ll a;
        cin >> a;
        st.insert(a);
    }   

    g = vector<vector<pair<ll, ll>>>(n + 1, vector<pair<ll, ll>>());
    for(ll i = 0; i < m; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    vector<bool> vis(n + 1, false);
    queue<ll> q;
    q.push(1);
    vis[1] = true;
    while(!q.empty()){
        ll u = q.front(); q.pop();
        for(auto &[v, _] : g[u]){
            if(!vis[v]){
                vis[v] = true;
                q.push(v);
            }
        }
    }

    if(!vis[n]){
        cout << "-1\n";
        return;
    }

    vector<ll> d1, d2;
    dijkstra(1, st, d1, d2, n);

    vector<ll> dW, dR;
    dijkstra(n, st, dW, dR, n);

    ll res = INF;
    for(ll v = 1; v <= n; v++){
        ll ma = min(d1[v], d2[v]);
        ll ro = min(dW[v], dR[v]);

        res = min(res, max(ma, ro));
    }

    cout << res << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--){
        sol();
    }
}
