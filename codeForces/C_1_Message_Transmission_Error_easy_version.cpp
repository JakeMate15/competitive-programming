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

template<typename I>
vector<int> Z(I first, I last) {
    const size_t n = last - first;
    vector<int> zf(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        zf[i] = max(0, min(r - i, zf[i - l]));
        while (i + zf[i] < n && *(first + zf[i]) == *(first + zf[i] + i)) {
            ++zf[i];
        }
        if (i + zf[i] > r) {
            r = i + zf[i];
            l = i;
        }
    }
    return zf;
}

void sol() {
    string s;
    cin >> s;

    auto z = Z(all(s));
    ll a = sz(s);
    for (int q = 1; q * 2 < a; ++q) {
        if (z[q] >= a - q) {
            cout << "YES\n" << s.substr(q);
            return;
        }
    }
    cout << "NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    // cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}