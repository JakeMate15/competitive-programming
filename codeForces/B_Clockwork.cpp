#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "/algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

void sol () {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &x: arr) {
        cin >> x;
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] <= max(i, n - i - 1) * 2) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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