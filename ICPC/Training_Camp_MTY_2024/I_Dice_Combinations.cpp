#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()
#define sz(a)   (int)a.size()
typedef long long ll;

const int mod = 1e9 + 7;

int main () {
    int n;
    cin >> n;

    vector<int> dp(n + 5, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                (dp[i] += dp[i - j]) %= mod;
            }
        }
    }

    cout << dp[n] << "\n";

    return 0;
}