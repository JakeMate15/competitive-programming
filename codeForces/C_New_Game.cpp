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

    vector<pair<int, int>> arr(cnt.begin(), cnt.end());
    int ans = arr[0].second, tam = 1, curr = arr[0].second, ult = 0;
    for (int i = 1; i < arr.size(); i++) {
        debug(ans, tam, curr, ult, k);
        if (arr[i].first == arr[i - 1].first + 1) {
            if (tam < k) {
                curr += arr[i].second;
                tam++;
            } else {
                curr -= arr[ult].second;
                ult++;
                curr += arr[i].second;
            }
        } else {
            ult = i;
            tam = 1;
            curr = arr[i].second;
        }
        ans = max(ans, curr);
    }

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