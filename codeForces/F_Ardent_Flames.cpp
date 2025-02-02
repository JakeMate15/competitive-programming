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
typedef pair<ll, ll> ii;

const ll MX = 1E18 + 5;
const int MOD = 1E9 + 7;

ll floor_div(ll x, ll y) {
    assert(y != 0);
    if (y < 0) {
        y = -y;
        x = -x;
    }
    if (x >= 0) return x / y;
    return (x + 1) / y - 1;
}
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
    int n;
    ll m, k;
    cin >> n >> m >> k;

    ll mx = 0;
    vector<ll> h(n), x(n);
    for (auto &x: h) {
        cin >> x;
        mx = max(x, mx);
    }
    for (auto &xx: x) {
        cin >> xx;
    }

    ll lo = 1, hi = mx;
    auto ok = [&](ll t) -> bool {
        vector<ii> arr;
        for (int i = 0; i < n; ++i) {
            ll mx = ceil_div(h[i], t);

            if (mx > m) {
                continue;
            }

            ll l = x[i] - m + mx;
            ll r = x[i] + m - mx;
            arr.emplace_back(l, 1);
            arr.emplace_back(r + 1, -1);
        }

        if (!sz(arr)) {
            return false;
        }

        sort(all(arr));

        ll c = 0;
        for (int i = 0; i < sz(arr); i++) {
            c += arr[i].second;
            if (c >= k) {
                return true;
            }
        }
        return false;
    };

    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (ok(mid))
            hi = mid;
        else
            lo = mid + 1;
    }

    if (lo <= mx && ok(lo)) {
        cout << lo << '\n';
    } else {
        cout << -1 << '\n';
    }
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