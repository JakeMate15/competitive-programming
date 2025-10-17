#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include "/algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

#define sz(a)       (int) a.size()
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()

const int MX = 2E5 + 5;
const int MOD = 1E9 + 7;

void sol () {
    int n, k;
    cin >> n >> k;
    vector<int64_t> l(n), r(n), mn(n), mx(n);
    for (int i = 0; i < n; i++) 
        cin >> l[i];
    for (int i = 0; i < n; i++) 
        cin >> r[i];
        
    int64_t sMax = 0;
    for (int i = 0; i < n; i++) {
        mn[i] = min(l[i], r[i]);
        mx[i] = max(l[i], r[i]);
        sMax += mx[i];
    }
    sort(rall(mn));
    int64_t sE = 0;
    for (int i = 0; i < k - 1; i++) {
        sE += mn[i];
    }
    cout << (sMax + sE + 1) << "\n";
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