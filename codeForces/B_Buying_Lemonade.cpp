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

    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    int64_t prefS = 0;
    int mn = 0, cuantos = 0, cnt2 = 0;
    for (const auto &[v, r]: cnt) {
        prefS += int64_t(v - mn) * (n - cuantos);
        
        if (prefS >= k) {
            cout << cnt2 + k << "\n";
            return;
        }

        cnt2 += r;
        mn = v;
        cuantos += r;
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