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
    ll l, r, i, k;
    cin >> l >> r >> i >> k;

    auto get = [] (ll n) -> ll {
        if (n < 0) return 0;
        if (n % 4 == 0) return n;
        else if (n % 4 == 1) return 1;
        else if (n % 4 == 2) return n + 1;
        return 0;
    };

    auto div = [] (ll a, ll b) -> ll {
        if (b == 0) {
            return 0;
        }
        if (a >= 0) {
            return a / b;
        } else {
            if (a % b == 0) {
                return a / b;
            } else {
                return a / b - 1;
            }
        }
    };

    ll s = 1LL << i;
    ll tot = get(r) ^ get(l - 1);
    ll mn = div(l - k + s - 1, s), mx = div(r - k, s);
    mn = max(0LL, mn);

    if (mx < mn) {
        cout << tot << "\n";
        return;
    }

    ll n = mx - mn + 1;
    ll lsb = k % s;
    ll c = k >> i;
    ll x1 = get(mx) ^ get(mn - 1);
    ll XOR;
    
    if (n % 2 == 1) {
        XOR = lsb ^ (c << i) ^ (x1 << i);
    } else {
        XOR = x1 << i;
    }

    ll ans = tot ^ XOR;
    debug(ans, tot, XOR);

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