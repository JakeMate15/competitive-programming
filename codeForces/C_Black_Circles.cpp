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

    vector<ii> pt(n), pt2(2);
    for (auto &[x, y]: pt) {
        cin >> x >> y;
    }

    for (auto &[x, y]: pt2) {
        cin >> x >> y;
    }

    auto dist = [] (ii a, ii b) -> ld {
        ld x = a.first - b.first;
        ld y = a.second - b.second;

        return hypot(x, y);
    };

    ld d = dist(pt2[0], pt2[1]);
    for (int i = 0; i < n; i++) {
        ld d1 = dist(pt2[1], pt[i]);

        if (d1 <= d) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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