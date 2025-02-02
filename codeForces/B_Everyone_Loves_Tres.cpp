#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...) 
#endif

void sol () {
    int n;
    cin >> n;

    if (n == 1 || n == 3) {
        cout << -1 << "\n";
        return;
    }

    string s(n, '3');
    s[n - 1] = s[n - 2] = '6';
    if (n & 1) {
        s[n - 4] = '6';
    } 

    cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    // for (int i = 0; i < 20; i++) {
    //     cout << 66 * i << "\n";
    // }

    while(t--) {
        sol();
    }

    return 0;
}