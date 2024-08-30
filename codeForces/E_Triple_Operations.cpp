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

int lg3[MX];

void sol () {
    int l, r;
    cin >> l >> r;

    int ans = lg3[r] - lg3[l - 1];
    ans += lg3[l] - lg3[l - 1];

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    for (int i = 1; i < MX; i++) {
        int n = i;
        while (n) {
            lg3[i]++;
            n /= 3;
        }

        lg3[i] += lg3[i -1];
    }

    while(t--) {
        sol();
    }

    return 0;
}