#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

int ask (int r) {
    cout << "? " << 1 << " " << r << "\n";
    int ans;
    cin >> ans;
    return ans;
}

void ans (string res, bool found, int n) {
    debug(res);
    if (!found) {
        res = "IMPOSSIBLE";
    }
    // assert(res.size() == n);
    cout << "! " << res << "\n";
}

void sol () {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 1; i < n; i++) {
        arr[i] = ask(i + 1);
    }

    bool ok = false;    
    string r = "";
    for (int i = 1; i < n; i++) {
        debug(i, r);
        if (arr[i] > arr[i - 1]) {
            if (!ok) {
                r += string(i - arr[i], '1');
                debug(string(i - arr[i], '1'));
                r += string(arr[i], '0');
                debug(string(arr[i], '0'));
            }
            ok = true;  
            r += "1";
        } else if (ok) {
            r += "0";
        }
    }

    ans(r, ok, n);
}

int main() {
    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}