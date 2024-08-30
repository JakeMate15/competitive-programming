#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

#define sz(a)       (int) a.size()
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int MX = 2E5 + 5;
const int MOD = 1E9 + 7;

void sol () {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (auto &x: arr) {
        cin >> x;
    }

    sort(rall(arr));

    ll res = 0;
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            int aux = min(k, arr[i - 1] - arr[i]);
            res -= aux + arr[i];
            k -= aux;
        } else {
            res += arr[i];
        }
    }

    cout << res << "\n";
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