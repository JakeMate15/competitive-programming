#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...)
#endif

void sol () {
    int64_t n, m, r, c;
    cin >> n >> m >> r >> c;

    int64_t ans = m - c + (n - r) * (m - 1) + m * (n - r);

    cout << ans << "\n";
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