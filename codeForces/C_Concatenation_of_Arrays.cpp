#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

void sol () {
    int n;
    cin >> n;

    vector<tuple<int, int, int>> arr(n);
    for (auto &[s, a, b]: arr) {
        cin >> a >> b;
        s += (a + b);
    }

    sort(arr.begin(), arr.end());

    for (auto &[s, a, b]: arr) {
        cout << a << " " << b << " ";
    }
    cout << "\n";
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