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
    int n;
    ll m;
    cin >> n >> m;
    
    map<int, int> f;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        f[a[i]] = c;
    }
    
    ll ans = 0;
    for (auto [x, y] : f) {
        ans = max(ans, 1LL * x * min<ll>(y, m / x));
        if (f.contains(x + 1)) {
            int z = f[x + 1];
            ll c;
            if (1LL * x * y >= m) {
                c = m / x;
            } else {
                c = y + min<ll>(z, (m - 1LL * x * y) / (x + 1));
            }
            ans = max(ans, min(m, c * x + min<ll>(c, z)));
        }
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