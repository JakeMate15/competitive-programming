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
    int n;
    cin >> n;

    int s = 0;
    vector<int> arr(n), cnt(3);
    for (auto &x: arr) {
        cin >> x;
        s += x;
        cnt[x % 3]++;
    }

    if (s % 3 == 0) {
        cout << 0;
    } else if (s % 3 == 2) {
        cout << 1;
    } else {
        int ok = (cnt[1] > 0 ? 1 : 2);
        cout << min(2, ok);
    }

    cout << "\n";
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