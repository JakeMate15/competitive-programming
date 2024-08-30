#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

#define sz(a)       (int) a.size()
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const ll MX = 2E5 + 5;
const int MOD = 1E9 + 7;

ll fact[MX], inv[MX];

ll binPow(ll a, ll n) {
    a %= MOD;
    ll res = 1;
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

ll C(int n, int k) {
    if (k > n)
        return 0;
    return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

void sol () {
    int n, k;
    cin >> n >> k;

    int cnt[2] = {0, 0};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    ll res = 0;
    for (int unos = (k + 1) / 2; unos <= k; unos++) {
        (res += C(cnt[1], unos) * C(cnt[0], k - unos) % MOD) %= MOD;
    }

    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    preCalc();

    while(t--) {
        sol();
    }

    return 0;
}