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

int ask (int mid) {
    cout << "? " << mid << " " << mid << "\n";
    cout.flush();
    int r;
    cin >> r;
    return r;
}

void sol () {
    int lo = 1, hi = 1000;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        int r = ask(mid);
 
        if (r > mid * mid)
            hi = mid;
        else 
            lo = mid;
    }
 
    cout << "! " << hi << "\n";
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