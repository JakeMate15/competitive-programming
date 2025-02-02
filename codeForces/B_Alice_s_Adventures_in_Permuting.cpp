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
    ll n, b, c;
    cin >> n >> b >> c;

    ll ans = -1;
    if (b == 0) {
        if (n - 2 <= c) {
            if (c >= n) {
                ans = n; 
            } else {
                ans = n - 1;
            } 
        }
    } else {
        ll l = c, r = b * (n - 1) + c;
        ll in = (n - 1 >= l ? n - l : 0);
        in = (in + b - 1) / b;

        ans = n - in;
    }

    cout << ans << "\n";
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