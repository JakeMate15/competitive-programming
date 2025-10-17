#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    int res = 0;
    int saltos = sqrt(2 * n) + 2;

    vector<vector<int>> dp(n, vector<int>(saltos, 0));
    dp[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '#') 
            continue;

        for (int j = 0; j < saltos; ++j) {
            if (dp[i][j] == 0) 
                continue;
            if (i + 1 < n)
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
            else
                res = (res + dp[i][j]) % MOD;
        }

        for (int j = 0; j < saltos - 1; ++j) {
            if (dp[i][j] == 0) 
                continue;
            int I = i + j + 2;
            if (I < n)
                dp[I][j + 1] = (dp[I][j + 1] + dp[i][j]) % MOD;
            else
                res = (res + dp[i][j]) % MOD;
        }
    }

    cout << res << '\n';
    return 0;
}
