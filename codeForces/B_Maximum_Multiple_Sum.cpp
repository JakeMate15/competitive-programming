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

int s(int n, int x) {
    int k = n / x;
    return x * (k * (k + 1)) / 2;
}
 
void sol() {
    int n;
    cin >> n;
    int res = 2;
    int curr = s(n, 2);
 
    for (int x = 3; x <= n; ++x) {
        int cs = s(n, x);
        if (cs > curr) {
            curr = cs;
            res = x;
        }
    }
 
    cout << res << endl;
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