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
    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> arr(m);
    for (int i = 0; i < m; i++) {
        cin >> arr[i][0] >> arr[i][1];
        arr[i][2] = i;
    }

    sort(all(arr), [] (auto a, auto b) {
        return a[1] < b[1];
    });

    ll s = 0;
    vector<array<int, 3>> ans(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        ans[i] = arr[i];
        s += arr[i][1];
    }

    sort(all(ans), [] (auto a, auto b) {
        return a[0] < b[0];
    });

    cout << s << "\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i][2] + 1 << " " << ans[2 * n - 1 - i][2] + 1 << "\n";
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