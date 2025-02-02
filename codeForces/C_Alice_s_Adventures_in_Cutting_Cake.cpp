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

void sol () {RAYA
    int n,m;
    ll v;
    cin >> n >> m >> v;

    vector<ll> sum(n + 1), a(n + 1);
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    ll s = 0;
    vector<int> vl = {0}, vr = {n};
    for(int i = 1; i <= n; i++){
        s += a[i];
        if(s >= v){
            s = 0;
            vl.push_back(i);
        }
    }

    s = 0;
    for (int i = n; i >= 1; i--) {
        s += a[i];
        if(s >= v){
            s = 0;
            vr.push_back(i - 1);
        }
    }

    debug(a);
    debug(sum);
    debug(vl);
    debug(vr);

    ll ans = -1;
    for(int t = 0; t <= m; t++) {
        if(sz(vl) >= t + 1 && sz(vr) >= m - t + 1) {
            s = sum[vr[m - t]] - sum[vl[t]];
            ans = max(ans, s);
            debug(s);
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