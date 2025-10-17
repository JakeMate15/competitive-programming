#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "/algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

#define sz(a)       (int) a.size()
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()

const int MX = 2E5 + 5;
const int MOD = 1E9 + 7;

void sol () {
    int n, l, r;
    cin >> n >> l >> r;
    l--, r--;

    vector<int> left, right;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i <= r) {
            left.push_back(x);
        } 
        if (i >= l) {
            right.push_back(x);
        }
    }

    sort(all(left));
    sort(all(right));

    int64_t x = 0, y = 0;
    for (int i = 0; i < r - l + 1; i++) {
        x += left[i];
        y += right[i];
    }
    cout << min(x, y) << "\n";
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