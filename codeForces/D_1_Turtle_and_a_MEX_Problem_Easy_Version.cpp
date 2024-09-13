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

    auto gaus = [] (ll n) -> ll {
        if (n <= 0)
            return 0LL;
        return n * (n + 1) / 2;
    };
    
    int mex = 0;
    for (int i = 0; i < n; i++) {
        int l, x;
        cin >> l;

        set<int> st;
        for (int j = 0; j < l; j++) {
            cin >> x;
            st.insert(x);
        }

        int cmex = 0;
        bool f = true;
        while (st.count(cmex) || f) {
            f &= st.count(cmex);
            cmex++;
        }

        mex = max(mex, cmex);
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