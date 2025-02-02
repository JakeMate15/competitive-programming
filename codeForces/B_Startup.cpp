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
    int n, k;
    cin >> n >> k;

    map<int, ll> mp;
    for (int i = 0; i < k; ++i) {
        int b_i, c_i;
        cin >> b_i >> c_i;
        mp[b_i] += c_i;
    }

    vector<ll> arr;
    for (auto& [v, r] : mp) {
        arr.push_back(r);
    }

    sort(rall(arr));

    int who = min(n, sz(arr));
    ll ans = 0;
    for (int i = 0; i < who; ++i) {
        ans += arr[i];
    }

    cout << ans << '\n'; 
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