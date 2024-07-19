#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()
#define sz(a)   (int) a.size()

typedef long long ll;
typedef pair<int, int> ii;

const int inf = 1e9 + 7;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    string s;
    cin >> s;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    auto get = [] (int x) {
        return x * (x + 1) / 2;
    };

    function<int(int, int)> go = [&](int p, int k) -> int {
        if (k < 0) 
            return inf;
        if (p >= n) 
            return 0;
        if (dp[p][k] != -1) 
            return dp[p][k];
        if (s[p] == '0') 
            return go(p + 1, k);
        
        dp[p][k] = inf;
        int i;
        for (i = p; i < n && s[i] == '1'; i++) {
            dp[p][k] = min(dp[p][k], go(i + 1, k - 1) + get(i - p));
        }
        dp[p][k] = min(dp[p][k], go(i + 1, k) + get(i - p));
        return dp[p][k];
    };

    int lo = -1, hi = n + 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;

        if (go(0, mid) <= m)
            hi = mid;
        else
            lo = mid;
    }

    cout << hi << "\n";

    return 0;
}