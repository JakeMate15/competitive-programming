#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

int64_t binPow(int64_t x, int64_t n, int64_t MOD = 1E9 + 7) {
    assert(n >= 0);
    x %= MOD;
    int64_t res = 1;
    
    while (n > 0) {
        if (n & 1)
            res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    
    return res;
}

void sol () {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
    }

    vector<int> k(n);
    for (auto &x: k) {
        cin >> x;
        cout << binPow(2, x) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}