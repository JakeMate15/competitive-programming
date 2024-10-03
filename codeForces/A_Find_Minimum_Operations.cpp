#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...)
#endif

void sol () {
    int64_t n, k;
    cin >> n >> k;

    int res = 0;
    while (k != 1 && n >= k) {
        res++;
        int64_t p = 1;
        while (p * k <= n) {
            p *= k;
        }
        n -= p;
    }

    cout << res + n << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}