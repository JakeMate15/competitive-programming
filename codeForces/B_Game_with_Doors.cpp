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
    ii a, b;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;

    if (a > b) {
        swap(a, b);
    } 

    if (a.second < b.first || a.second == b.first) {
        cout << "1" << "\n";
        return;
    }

    int l = max(a.first, b.first), r = min(a.second, b.second);
    int res = r - l;

    res += a.first != b.first;
    res += a.second != b.second;

    cout << res << "\n";
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