#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...)
#endif

#define all(a)      a.begin(), a.end()

void sol () {
    int n;
    cin >> n;

    int pot = 1, p = 1;
    while (pot * 2 <= n) {
        pot *= 2;
        p++;
    }

    vector<int> aux(n);
    iota(all(aux), 1);
    set<int> disp(all(aux));

    vector<int> ans(n + 1);
    for (int i = (n & 1 ? n - 1 : n); i >= 2 && pot >= 1; i -= 2) {
        if (pot == 1) {
            ans[i] = 5;
        } else {
            ans[i] = pot;
            ans[i - 1] = pot - 1;
        }
        disp.erase(ans[i]);
        disp.erase(ans[i - 1]);
        pot /= 2;
    }

    if (n & 1) {
        ans.back() = n;
        disp.erase(n);
    }

    for (int i = 1; i <= n; i++) {
        if (!ans[i]) {
            ans[i] = *disp.begin();
            disp.erase(ans[i]);
        }
    }

    if (n <= 5) {
        swap(ans[1], ans[2]);
    }

    cout << (n & 1 ? n : (1 << p) - 1) << "\n";
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
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