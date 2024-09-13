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
    int n, q;
    cin >> n >> q;

    vector<ll> arr(n * 2);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i + n] = arr[i];
    }

    for (int i = 1; i < 2 * n; i++) {
        arr[i] += arr[i - 1];
    }

    auto query = [&] (int l, int r) -> ll {
        if (l <= 0)
            return arr[r];
        return arr[r] - arr[l - 1];
    };

    while (q--) {
        ll l, r;
        cin >> l >> r;
        l--, r--;

        int p1 = l / n, p2 = r / n;
        ll sep = p2 - p1 - 1;

        p1 %= n, p2 %= n;
        l %= n, r %= n;

        ll res = 0;
        if (p1 == p2) {
            res += query(l + p1, r + p1);
        } else {    
            res += arr[n - 1] * sep;
            res += query(p2, p2 + r);
            res += query(p1 + l, p1 + n - 1);
        }

        cout << res << "\n";
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