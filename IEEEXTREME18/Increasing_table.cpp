#include<bits/stdc++.h>
using namespace std;

#define sz(a)       (int) a.size()
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int Mx = 2E5 + 5;
const int MOD = 998244353;

void sol () {
    int n;
    cin >> n;
    
    int x;
    cin >> x;
    set<int> st;
    for (int i = 0; i < x; ++i) {
        int a;
        cin >> a;
        st.insert(a);
    }

    int y;
    cin >> y;
    set<int> st2;
    for (int i = 0; i < y; ++i) {
        int b;
        cin >> b;
        st2.insert(b);
    }

    int N = 2 * n;
    vector<vector<int>> dp(N + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (dp[i][j] > 0) {
                int number = i + 1;
                if (st.count(number)) {
                    if (j + 1 <= n) {
                        dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
                    }
                } else if (st2.count(number)) {
                    if (j - 1 >= 0) {
                        dp[i + 1][j - 1] = (dp[i + 1][j - 1] + dp[i][j]) % MOD;
                    }
                } else {
                    if (j + 1 <= n) {
                        dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
                    }
                    if (j - 1 >= 0) {
                        dp[i + 1][j - 1] = (dp[i + 1][j - 1] + dp[i][j]) % MOD;
                    }
                }
            }
        }
    }

    cout << dp[N][0] << endl;
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