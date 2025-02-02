#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

void sol () {
    int n;
    cin >> n;

    vector<int64_t> arr(n);
    for (int64_t &x: arr) {
        cin >> x;
    }

    auto ok = [&] (int64_t k) -> bool {
        int cnt = 0, f = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n && !f; j++) {
                if (i == j) {
                    continue;
                }

                if (abs(arr[i] - arr[j]) <= k) {
                    f = true;
                    // debug(i);
                }
            }

            cnt += !f;
            if (cnt >= 2) {
                return false;
            }
        }
        return true;
    };

    debug(ok(1));

    // int64_t lo = 0, hi = 1E18 + 5;
    // while (lo + 1 < hi) {
    //     int64_t mid = (lo + hi) / 2;

    //     if (ok(mid)) {
    //         hi = mid;
    //     } else {
    //         lo = mid;
    //     }
    // }

    // cout << hi << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}