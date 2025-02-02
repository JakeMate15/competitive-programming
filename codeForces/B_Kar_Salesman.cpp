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
    int n, k;
    cin >> n >> k;

    int64_t sum = 0, mx = 0;
    vector<int64_t> arr(n);
    for (auto &x: arr) {
        cin >> x;
        sum += x;
        mx = max(mx, x);
    }

    cout << max(mx, (sum + k - 1) / k) << "\n";
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