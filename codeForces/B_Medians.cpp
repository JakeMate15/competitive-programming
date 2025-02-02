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

    if (n == 1) {
        if (k == 1) {
            cout << 1 << "\n" << 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
        return;
    }

    int l = k - 1;
    int r = n - k;
    if (l < 0 || r < 0) {
        cout << -1 << "\n";
        return;
    }

    if (l % 2 == 0) l--;
    if (r % 2 == 0) r--;

    if (l < 0 || r < 0) {
        cout << -1 << "\n";
        return;
    }

    int m = 3;
    vector<int> p = {1, l + 1, n - r + 1};
    if (p[2] > n + 1) {
        cout << -1 << "\n";
        return;
    }

    cout << m << "\n";
    for (int i = 0; i < m; ++i) {
        cout << p[i] << (i + 1 == m ? '\n' : ' ');
    }
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