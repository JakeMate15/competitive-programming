#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

const int MX = 2E5 + 5;
vector<int> ans(MX);

void sol () {
    int n;
    cin >> n;

    int idx = 1;
    if (n % 2 == 0) {
        for (int i = 0; i < n; i += 2) {
            cout << idx << " " << idx << " \n"[i == n - 2];
            idx++;
        }
    } else if (n & 1 && n >= 27) {
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i == n - 1];
        }
    } else {
        cout << "-1\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    ans[0] = ans[9] = ans[25] = 1;
    ans[26] = ans[22] = 2;
    int idx = 3;
    for (int i = 0; i < MX; i++) {
        if (ans[i]) {
            continue;
        } else {
            ans[i] = ans[i + 1] = idx++;
            i++;
        }
    }

    while(t--) {
        sol();
    }

    return 0;
}