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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    vector<int> tm(n);
    for (int i = 0; i < n; i++) {
        cin >> tm[i];
    }

    int cur = 0;
    for (int i = 0; i < n; i++) {
        int need = a[i] - (i - 1 < 0 ? 0 : b[i - 1]) + tm[i];
        cur += need;
        if (i + 1 < n) {
            int wait = (b[i] - a[i] + 1) / 2;
            cur += wait;
            if (cur < b[i]) {
                cur = b[i];
            }
        }
    }
    cout << cur << '\n';
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