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
    string s;
    cin >> s;
    int n = sz(s);
    int cnt = 0;

    for (int i = 0; i <= n - 4; ++i) {
        if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0') {
            cnt++;
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int i, v;
        cin >> i >> v;
        i--; 

        if (s[i] - '0' == v) {
            cout << (cnt > 0 ? "YES\n" : "NO\n");
            continue;
        }

        for (int j = i - 3; j <= i; ++j) {
            if (j >= 0 && j + 3 < n) {
                if (s[j] == '1' && s[j + 1] == '1' && s[j + 2] == '0' && s[j + 3] == '0') {
                    cnt--;
                }
            }
        }

        s[i] = '0' + v;
        for (int j = i - 3; j <= i; ++j) {
            if (j >= 0 && j + 3 < n) {
                if (s[j] == '1' && s[j + 1] == '1' && s[j + 2] == '0' && s[j + 3] == '0') {
                    cnt++;
                }
            }
        }

        cout << (cnt > 0 ? "YES\n" : "NO\n");
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