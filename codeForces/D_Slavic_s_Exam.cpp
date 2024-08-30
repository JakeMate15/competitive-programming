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
    string a, b;
    cin >> a >> b;

    int j = 0;
    for (int i = 0; i < sz(a) && j < sz(b); i++) {
        if (a[i] == b[j]) {
            j++;
        } else if (a[i] == '?') {
            a[i] = b[j];
            j++;
        }
    }

    if (j < sz(b)) {
        cout << "NO\n";
        return;
    }

    for (auto &x: a) {
        x = (x == '?' ? 'a' : x);
    }

    cout << "YES\n";
    cout << a << "\n";
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