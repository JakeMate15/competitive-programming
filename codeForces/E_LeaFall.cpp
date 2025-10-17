#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
long long modExp(long long a, long long b){
    long long res = 1 % MOD;
    a %= MOD;
    while(b){
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
long long modInv(long long a){
    return modExp(a, MOD - 2);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<vector<int>> tree(n);
        vector<long long> r(n), pi(n), qi(n);
        for(int i = 0; i < n; i++){
            cin >> pi[i] >> qi[i];
            long long invq = modInv(qi[i]);
            r[i] = (1 - (pi[i] % MOD) * invq % MOD + MOD) % MOD;
        }
        for(int i = 0; i < n - 1; i++){
            int u, v; cin >> u >> v; u--; v--;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        vector<long long> prod(n, 1);
        for(int i = 0; i < n; i++){
            for(int nb : tree[i]){
                prod[i] = prod[i] * ((1 - r[nb] + MOD) % MOD) % MOD;
            }
        }
        vector<long long> sumN(n, 0);
        for(int i = 0; i < n; i++){
            for(int nb : tree[i]){
                long long term = r[nb];
                long long invTerm = modInv((1 - r[nb] + MOD) % MOD);
                term = term * invTerm % MOD;
                sumN[i] = (sumN[i] + term) % MOD;
            }
        }
        vector<long long> Ei(n, 0);
        long long L = 0;
        for(int i = 0; i < n; i++){
            Ei[i] = r[i] * prod[i] % MOD;
            Ei[i] = Ei[i] * sumN[i] % MOD;
            L = (L + Ei[i]) % MOD;
        }
        long long indep = ((L * L % MOD - L) % MOD + MOD) % MOD;
        indep = indep * modInv(2) % MOD;
        long long corr = 0;
        for(int u = 0; u < n; u++){
            for(int v : tree[u]){
                if(u < v){
                    long long inv1 = modInv((1 - r[v] + MOD) % MOD);
                    long long inv2 = modInv((1 - r[u] + MOD) % MOD);
                    long long Euv = r[u] * r[v] % MOD;
                    Euv = Euv * prod[u] % MOD;
                    Euv = Euv * inv1 % MOD;
                    Euv = Euv * prod[v] % MOD;
                    Euv = Euv * inv2 % MOD;
                    long long delta = (Euv - (Ei[u] * Ei[v] % MOD) + MOD) % MOD;
                    corr = (corr + delta) % MOD;
                }
            }
        }
        corr = corr * modInv(2) % MOD;
        long long ans = (indep + corr) % MOD;
        cout << ans % MOD << "\n";
    }
    return 0;
}
