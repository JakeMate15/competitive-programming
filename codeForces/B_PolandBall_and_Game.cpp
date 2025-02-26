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
    int n, m;
    cin >> n >> m;

    int c = 0;
    set<string> A;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        A.insert(s);
    }

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        
        if (A.count(s)) {
            c++;
        }
    }

    n -= c;
    m -= c;

    bool ok = false;
    if (n > m) {
        ok = true;
    } else if (n == m && c % 2 == 1) {
        ok = true;  
    }

    cout << (ok ? "YES" : "NO") << "\n";
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