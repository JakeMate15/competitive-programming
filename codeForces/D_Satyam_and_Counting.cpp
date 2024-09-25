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
    cin >> n;
        
    map<int, int> y0, y1;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        
        if (y == 0) 
            y0[x]++, cnt0++;
        else
            y1[x]++, cnt1++;
    }

    ll res = 0;
    for (auto &[x, r]: y0) {
        if (y1.find(x) != y1.end()) {
            res += max(0, cnt1 - 1);
        }

        bool x1 = y1.find(x - 1) != y1.end();
        bool x2 = y1.find(x + 1) != y1.end();

        res += (x1 && x2);
    }

    for (auto &[x, r]: y1) {
        if (y0.find(x) != y0.end()) {
            res += max(0, cnt0 - 1);
        }
        
        bool x1 = y0.find(x - 1) != y0.end();
        bool x2 = y0.find(x + 1) != y0.end();

        res += (x1 && x2);
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