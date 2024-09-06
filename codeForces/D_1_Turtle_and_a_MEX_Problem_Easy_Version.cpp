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
    int n, k;
    cin >> n >> k;

    auto getMex = [] (const vector<int> &v) -> int {
        bool f = true;
        set<int> st(all(v));
        int mex = 0;

        while (true) {
            if (st.count(mex)) {
                mex++;
            } else if (f) {
                mex++;
                f = false;
            } else {
                break;
            }
        }

        return mex;
    };

    auto gaus = [] (ll n) -> ll {
        if (n <= 0)
            return 0LL;
        return n * (n + 1) / 2;
    };
    
    int mex = 0;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;

        vector<int> arr(l);
        for (auto &x: arr) {
            cin >> x;
        }

        mex = max(mex, getMex(arr));
    }

    ll res = 0;
    if (k > mex) {
        res += gaus(k) - gaus(mex);
        res += 1LL * mex * (mex + 1);
    } else {
        // mex = min(mex, k);
        res += 1LL * mex * (k + 1);
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