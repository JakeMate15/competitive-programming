#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    // #include "algoDebug.h"
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

    vector<ii> arr(n);
    for (auto &[a, b]: arr) {
        cin >> a >> b;
    }

    for (int i = -100; i <= 100; i++) {
        for (int j = -100; j <= 100; j++) {
            int cnt = 0;
            for (auto [a, b]: arr) {
                if ((a <= i && i <= b) || (a <= j && j <= b)) {
                    cnt++;
                }
            }

            if (cnt == n) {
                cout << i << " " << j << "\n";
                return;
            }
        }
    }

    cout << -1 << "\n";
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