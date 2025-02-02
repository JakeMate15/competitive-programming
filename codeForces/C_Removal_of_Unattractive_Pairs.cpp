#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "/algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

void sol () {
    int n;
    string s;
    cin >> n >> s;

    vector<int> a(26);
    for(auto x: s) {
        a[x - 'a']++;
    }

    auto mx = *max_element(a.begin(), a.end());
    if(mx > n / 2) {
        cout << 2 * mx - n << "\n";
    } else {
        cout << (n & 1)<< "\n";
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