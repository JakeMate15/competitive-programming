#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

#define sz(a)   (int) a.size()

void sol () {
    string a, b;
    cin >> a >> b;

    int ans = 0;
    int n = min(sz(a), sz(b)), tam = 0;;
    for (int i = 0; i < n && a[i] == b[i]; i++) {
        ans++;
        tam++;
    }

    ans += (tam > 0);
    ans += sz(a) - tam;
    ans += sz(b) - tam;

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}