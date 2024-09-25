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

/*
python ml
go rte
*/

void sol () {
    int n;
    string s;
    cin >> n >> s;

    int cnt[n + 5][26][2] = {};
    for (int i = 1; i <= n; i++) {
        cnt[i][s[i - 1] - 'a'][i % 2]++;
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 26; j++) {
            for (int k = 1; k <= n; k++) {
                cnt[k][j][i] += cnt[k - 1][j][i];
            } 
        }
    }

    int res = MX;
    if (n & 1) {
        for (int i = 1; i <= n; i++) {
            int pa = 0, im = 0;
            for (int c = 0; c < 26; c++) {
                pa = max(pa, cnt[i - 1][c][0] + cnt[n][c][1] - cnt[i][c][1]);
                im = max(im, cnt[i - 1][c][1] + cnt[n][c][0] - cnt[i][c][0]);
            }

            res = min(res, n - pa - im);
        }
    } else {
        int mx1 = 0, mx2 = 0;
        for (int i = 0; i < 26; i++) {
            mx1 = max(mx1, cnt[n][i][0]);
            mx2 = max(mx2, cnt[n][i][1]);
        }
        res = n - mx1 - mx2;
    }

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