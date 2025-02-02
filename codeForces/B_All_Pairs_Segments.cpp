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
    int n, q;
    cin >> n >> q;

    vector<int64_t> arr(n);
    for (auto &x: arr) {
        cin >> x;
    }

    map<int64_t, int64_t> cnt;
    for (int i = 0; i < n - 1; i++) {
        cnt[1LL * (i + 1) * (n - i - 1)] += (arr[i + 1] - arr[i] - 1);
        debug((i + 1) * (n - i + 1));
    }

    for (int i = 1; i <= n; i++) {
        cnt[1LL * (i - 1) * (n - i) + i - 1 + n - i] += 1;
    }

    debug(cnt);

    for (int i = 0; i < q; i++) {
        int64_t x;
        cin >> x;
        cout << cnt[x] << " \n"[i == q - 1];
    }
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