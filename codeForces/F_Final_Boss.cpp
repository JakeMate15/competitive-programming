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

ll ceil_div(ll x, ll y) {
    assert(y != 0);
    if (y < 0) {
        y = -y;
        x = -x;
    }
    if (x <= 0) return x / y;
    return (x - 1) / y + 1;
}

void sol () {
    ll h, n;
    cin >> h >> n;

    vector<int> d(n), c(n);
    for (auto &x: d) {
        cin >> x;
    }
    for (auto &x: c) {
        cin >> x;
    }

    ll lo = 0, hi = 1E11;
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;

        ll s = 0;
        for (int i = 0; i < n; i++) {
            s += ceil_div(mid, c[i]) * d[i];
            if (s >= h) {
                break;
            }
        }

        if (s >= h)
            hi = mid;
        else
            lo = mid;
    }

    cout << hi << "\n";
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