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

ll g (ll n) {
    return n * (n + 1) / 2;
}

ll query (int l, int r) {
    ll res = g(r) - g(l - 1);
    return res;
}

void sol () {
    int n, k;
    cin >> n >> k;
    
    int l = k, r = k + n - 1;

    int lo = l, hi = r;
    auto get = [&] (int m) -> ll {
        ll s1 = query(lo, m);
        ll s2 = query(m + 1, hi);

        return abs(s1 - s2);
    };

    RAYA
    debug(l, r);
    while (r - l > 2) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        
        raya
        debug(m1, get(m1));
        debug(m2, get(m2));
        if (get(m1) > get(m2)) {
            l = m1;
        } else {
            r = m2;
        }
    }

    ll x_minimo = l;
    ll valor_minimo = get(x_minimo);
    for (int i = l + 1; i <= r; ++i) {
        if (get(i) < valor_minimo) {
            x_minimo = i;
            valor_minimo = get(i);
        }
    }

    cout << valor_minimo << "\n";
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