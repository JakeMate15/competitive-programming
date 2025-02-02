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

    string s1, s2;
    cin >> s1 >> s2;

    int unos = 0, ceros = 0;
    for (auto &c: s1) {
        if (c == '1') {
            unos++;
        } else {
            ceros++;
        }
    }

    for (auto &c: s2) {
        if (unos == 0 || ceros == 0) {
            cout << "NO\n";
            return;
        }

        if (c == '1') {
            ceros--;
        } else {
            unos--;
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