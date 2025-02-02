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
typedef pair<int, int64_t> ii;

const int MX = 2E5 + 5;
const int MOD = 1E9 + 7;

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void sol () {
    string s;
    cin >> s;

    int n = sz(s);

    auto Z = z_function(s);
    Z[0] = sz(s);
    
    // vector<int> cnt(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        if (Z[i] + i == n) {
            cnt[Z[i]]++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (cnt.count(Z[i])) {
            cnt[Z[i]]++;
        }
    }

    for (auto &[v, r]: cnt) {
        r--;
    }

    vector<ii> ans(all(cnt));
    for (int i = sz(cnt) - 2; i >= 0; i--) {
        ans[i].second += ans[i + 1].second;
    }

    cout << sz(ans) << "\n";
    for (auto &[a, b]: ans) {
        cout << a << " " << b << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    // cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}