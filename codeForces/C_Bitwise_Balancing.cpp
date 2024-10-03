#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...)
#endif

void sol () {
    int64_t B, C, D, a = 0;
    cin >> B >> C >> D;

    auto get = [] (int64_t x, int i) -> bool {
        return x & (1LL << i);
    };

    for (int i = 0; i < 64; i++) {
        bool b = get(B, i), c = get(C, i), d = get(D, i); 
        if ((!d && !c && b) || (d && c && !b)) {
            cout << "-1\n";
            return;
        }

        if ((d && !b) || (!d && b)) {
            a |= (1LL << i);
        }
    }

    assert((a | B) - (a & C) == D);

    cout << a << "\n";
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