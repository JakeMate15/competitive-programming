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
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    auto f = [] (int a, int b) -> int {
        if (a > b)
            return 1;
        if (a == b)
            return 0;
        return -1;
    };

    int ans = 0;
    if (f(a, c) + f(b, d) > 0)
        ans += 1;
    if (f(a, d) + f(b, c) > 0)
        ans += 1;
    if (f(b, c) + f(a, d) > 0)
        ans += 1;
    if (f(b, d) + f(a, c) > 0)
        ans += 1;
    

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