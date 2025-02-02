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

    int cnt = 0;
    while (n--) {
        char c;
        int b;
        cin >> c >> b;

        debug(cnt, c, b);

        if (c == 'P') {
            cnt += b;
        } else {
            int bb = b;
            bb -= min(b, cnt);
            cout << (bb > 0 ? "YES" : "NO") << "\n";
            cnt -= min(b, cnt);
        }
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