#include <bits/stdc++.h>
using namespace std;
 
const int64_t MOD = 1000000007;
 
struct ModInt {
    int64_t value;
    ModInt(int64_t v = 0) {
        value = v % MOD;
        if(value < 0) value += MOD;
    }
    ModInt operator+(const ModInt &other) const { return ModInt(value + other.value); }
    ModInt operator-(const ModInt &other) const { return ModInt(value - other.value); }
    ModInt operator*(const ModInt &other) const { return ModInt(value * other.value); }
    ModInt pow(int64_t exp) const {
        ModInt base = *this, res = 1;
        while(exp > 0) {
            if(exp & 1) res = res * base;
            base = base * base;
            exp >>= 1;
        }
        return res;
    }
    ModInt inv() const { return pow(MOD - 2); }
    ModInt operator/(const ModInt &other) const { return *this * other.inv(); }
};
 
struct Comb {
    vector<ModInt> fact, invfact;
    int n;
    Comb(int n): n(n) {
        fact.resize(n+1);
        invfact.resize(n+1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * ModInt(i);
        invfact[n] = fact[n].inv();
        for (int i = n; i >= 1; i--) invfact[i-1] = invfact[i] * ModInt(i);
    }
    ModInt comb(int a, int b) {
        if(b < 0 || b > a) return 0;
        return fact[a] * invfact[b] * invfact[a-b];
    }
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int,int>>> adj(n);
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
 
    const int64_t INF = int64_t(1) << 60;
    vector<int64_t> dist(n, INF);
    priority_queue<pair<int64_t,int>, vector<pair<int64_t,int>>, greater<pair<int64_t,int>>> pq;
    dist[0] = 0;
    pq.push({0, 0});
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if(d != dist[u]) continue;
        for(auto edge : adj[u]){
            int v = edge.first, w = edge.second;
            if(dist[v] > d + w){
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
 
    vector<int64_t> ds;
    for (int i = 1; i < n; i++) ds.push_back(dist[i]);
    sort(ds.begin(), ds.end());
 
    vector<int64_t> uniqueD;
    vector<int> freq;
    for (int64_t d : ds)
        if(uniqueD.empty() || uniqueD.back() != d){
            uniqueD.push_back(d);
            freq.push_back(1);
        } else freq.back()++;
 
    int total = ds.size();
    Comb combStruct(total);
 
    ModInt totalComb = combStruct.comb(total, k), ans = 0;
    int cum = 0;
    for (size_t i = 0; i < uniqueD.size(); i++){
        int cntBefore = cum, cntGroup = freq[i];
        ModInt c1 = combStruct.comb(total - cntBefore, k);
        ModInt c2 = combStruct.comb(total - (cntBefore + cntGroup), k);
        ModInt ways = c1 - c2;
        ans = ans + ModInt(uniqueD[i] % MOD) * ways;
        cum += cntGroup;
    }
    ans = ans / totalComb;
    cout << ans.value;
    return 0;
}
