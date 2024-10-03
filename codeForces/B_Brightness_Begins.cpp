#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...)
#endif

void sol () {
    int64_t k;
    cin >> k;

    int64_t lo = 1, hi = 5E18;
    while (lo + 1 < hi) {
        int64_t mid = (lo + hi) / 2;

        if (mid - int64_t(sqrtl(mid)) >= k) {
            hi = mid;
        } else {
            lo = mid;   
        }
    }
    cout << hi << "\n";
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