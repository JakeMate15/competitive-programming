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

    string s;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    cin >> s;

    int cnt = 1;
    vector<int> color(n + 1);
    vector<int> res(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (color[i]) continue;

        for (int curr = i; !color[curr]; curr = p[curr]) {
            color[curr] = cnt;
            if (s[curr - 1] == '0') {
                res[cnt]++;
            }
        }

        cnt++;
    }

    RAYA
    debug(color);
    debug(res);

    for (int i = 1; i <= n; i++) {
        int who = color[i];
        cout << max(0, res[who]) << " \n"[i == n];
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