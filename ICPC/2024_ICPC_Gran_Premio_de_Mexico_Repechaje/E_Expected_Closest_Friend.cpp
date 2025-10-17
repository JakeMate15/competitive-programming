#include <bits/stdc++.h>
using namespace std;
 
const int MX = 1E5 + 5;
const int64_t INF = 1LL << 60;
const int64_t MOD = 1000000007;

int64_t fact[MX], inv[MX];

int64_t binPow(int64_t a, int64_t n) {
    a %= MOD;
    int64_t res = 1;
    while (n) {
        if (n & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

// No olvidar esto
void preCalc() {
    fact[0] = inv[0] = 1;
    for (int i = 1; i < MX; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = binPow(fact[i], MOD - 2);
    }
}

int64_t C(int n, int k) {
    if (k > n)
        return 0;
    return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
 
    vector<int64_t> dist(n, INF);
    priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> pq;
    dist[0] = 0;
    pq.push({0, 0});
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if(d == dist[u]) {
            for(auto [u, w] : g[u]) {
                if(dist[u] > d + w){
                    dist[u] = d + w;
                    pq.push({dist[u], u});
                }
            }
        }   
    }
 
    sort(dist.begin(), dist.end());
 
    vector<int64_t> uniqueD;
    vector<int> freq;
    for (int64_t d : dist) {
        if(uniqueD.empty() || uniqueD.back() != d){
            uniqueD.push_back(d);
            freq.push_back(1);
        } else {
            freq.back()++;
        }
    }
        
 
    int total = dist.size();
    int maxN = total;
    vector<int64_t> fact(maxN+1), invfact(maxN+1);
    fact[0] = 1;
    for (int i = 1; i <= maxN; i++)
        fact[i] = fact[i-1] * i % MOD;
 
    auto modexp = [&](int64_t base, int64_t exp) -> int64_t {
        int64_t res = 1;
        while(exp){
            if(exp & 1) res = res * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }
        return res;
    };
    invfact[maxN] = modexp(fact[maxN], MOD-2);
    for (int i = maxN; i >= 1; i--)
        invfact[i-1] = invfact[i] * i % MOD;
 
    auto comb = [&](int a, int b) -> int64_t {
        if(b < 0 || b > a) return 0;
        return fact[a] * invfact[b] % MOD * invfact[a-b] % MOD;
    };
 
    int64_t totalComb = comb(total, k), ans = 0;
    int cum = 0;
    for (size_t i = 0; i < uniqueD.size(); i++){
        int cntBefore = cum;
        int cntGroup = freq[i];
        int64_t c1 = comb(total - cntBefore, k);
        int64_t c2 = comb(total - (cntBefore + cntGroup), k);
        int64_t ways = (c1 - c2 + MOD) % MOD;
        ans = (ans + uniqueD[i] % MOD * ways) % MOD;
        cum += cntGroup;
    }
    int64_t invTotalComb = modexp(totalComb, MOD-2);
    ans = ans * invTotalComb % MOD;
    cout << ans;
    return 0;
}
