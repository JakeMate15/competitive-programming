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

    vector<string> g(n);
    for (auto &x: g) {
        cin >> x;
    }

    int ans = 0;
    int lim = min(n, m) / 2;
    for (int k = 0; k < lim; k++) {
        string s;
        for (int j = k; j < m - k; j++) {
            s += g[k][j];
        }

        for (int i = k + 1; i < n - k - 1; i++) {
            s += g[i][m - k - 1];
        }

        if (n - k - 1 != k) {
            for (int j = m - k - 1; j >= k; j--) {
                s += g[n - k - 1][j];
            }
        }

        if (m - k - 1 != k) {
            for (int i = n - k - 2; i > k; i--) {
                s += g[i][k];
            }
        }

        // s += s;
        size_t p = s.find('1');
        if (p != string::npos) 
            rotate(s.begin(), s.begin() + p, s.end());

        int cnt = 0;
        int pos = s.find("1543");
        while (pos != string::npos) {
            cnt++;
            pos = s.find("1543", pos + 1);
        }

        ans += cnt;
        debug(s);
    }

    cout << ans << endl;
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