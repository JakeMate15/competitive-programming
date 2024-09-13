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
    int n, a, b;
    cin >> n >> a >> b;

    int g = gcd(a, b);
    vector<int> arr(n);
    for (auto &x: arr) {
        cin >> x;
        x %= g;
    }

    sort(all(arr));

    int res = arr[n - 1] - arr[0];
    for (int i = 1; i < n; i++) {
        res = min(res, arr[i - 1] + g - arr[i]);
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