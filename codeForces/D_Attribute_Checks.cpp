#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

int n, m;
int cnt[5002][5002][2];
int dp[5002][5002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    int ult = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        if (x == 0) {
            ult++;
        } else if (x < 0) {
            cnt[ult][abs(x)][0]++;
        } else {
            cnt[ult][x][1]++;
        }
    }

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = -1;
            cnt[i][j][0] += cnt[i][j - 1][0];
            cnt[i][j][1] += cnt[i][j - 1][1];
        }
    }

    for (int i = m; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            int x = j;
            int y = i - j;
            int curr = cnt[i][j][0] + cnt[i][i - j][1];

            if (i == m) {
                dp[i][j] = curr;
            } else {
                dp[i][j] = curr + max(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }
    }

    cout << dp[0][0] << "\n";
    
    return 0;
}