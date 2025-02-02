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

    vector<int> arr(n);
    for (auto &x: arr) {
        cin >> x;
    }

    sort(arr.rbegin(), arr.rend());

    int64_t a = 0, b = 0;
    for (int i = 0; i < n; i += 2) {
        a += arr[i];

        if (i + 1 < n) {
            int dif = min(k, arr[i] - arr[i + 1]);
            k -= dif;
            b += arr[i + 1] + dif;
        } 
    }

    cout << a - b << "\n";
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