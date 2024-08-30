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
    string s;
    cin >> s;

    if (sz(s) < 3) {
        cout << "NO\n";
        return;
    }

    int a = 0, b = 0, p = 10;
    for (int i = 0; i < 2; i++) {
        a += (s[i] - '0') * p;
        p /= 10;
    }

    p = 1;
    for (int i = sz(s) - 1; i >= 2; i--) {
        b += (s[i] - '0') * p;
        p *= 10;
    }

    if (s[2] == '0' || a != 10 || b == 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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