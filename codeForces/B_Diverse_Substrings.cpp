#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...)
#endif

void sol () {
    int n;
    cin >> n;

    string arr;
    cin >> arr;

    int64_t res = 0;
    for (int i = 0; i < n; i++) {
        int mx = 0;
        map<int, int> cnt;   
        for (int j = i; j < min(i + 100, n); j++) {
            cnt[arr[j]]++; 
            mx = max(mx, cnt[arr[j]]);
            if (mx <= cnt.size()) {
                res++; 
            }
        }
    }

    cout << res << "\n";
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