#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...)
#endif

const int MOD = 1E9 + 7;

int64_t binPow(int64_t x, int64_t n) {
    assert(n >= 0);
    x %= MOD;
    int64_t res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % MOD;
        x = x * x % MOD, n >>= 1;
    }
    return res;
}

int64_t add(int64_t a, int64_t b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
    return a;
}
int64_t sub(int64_t a, int64_t b) {
    a -= b;
    if (a < 0) {
        a += MOD;
    }
    return a;
}
int64_t mul(int64_t a, int64_t b) {
    return a * b % MOD;
}
int64_t invMod(int64_t a) {
    return binPow(a, MOD - 2);
}
int64_t divMod(int64_t a, int64_t b) {
    return mul(a, invMod(b));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    
    vector<int64_t> pref(n + 1), prefC(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> pref[i];
        prefC[i] = add(prefC[i - 1], mul(pref[i], pref[i]));
        pref[i] = add(pref[i], pref[i - 1]);
    }
        
    while(q--){
        int l, r;
        cin >> l >> r;

        int64_t pL = sub(pref[r], pref[l - 1]);
        int64_t pC = sub(prefC[r], prefC[l - 1]);
        int64_t ans = mul(sub(mul(pL, pL), pC), 500000004);
 
        cout << ans << "\n";
    }

    return 0;
}