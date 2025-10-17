#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include "/algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

#define sz(a)       (int) a.size()
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()

const int MX = 2E5 + 5;
const int MOD = 1E9 + 7;
const int64_t INF = 4e18;

void sol() {
    int n;
    cin >> n;

    vector<vector<int64_t>> h(n, vector<int64_t>(n));
    for (auto &f : h) {
        for (auto &x : f) {
            cin >> x;
        }
    }

    vector<int64_t> a(n), b(n);
    for (auto& x : a) 
        cin >> x;
    for (auto& x : b) 
        cin >> x;

    auto msk = [&](bool hor) {
        int m = n - 1;
        vector<int> v(m, 0);
        for (int k = 0; k < m; ++k) {
            bool e0 = 0, ep = 0, en = 0;
            for (int i = 0; i < n; ++i) {
                int64_t d = hor ? h[i][k] - h[i][k + 1] : h[k][i] - h[k + 1][i];
                if (d == 0) e0 = 1;
                else if (d == 1) ep = 1;
                else if (d == -1) en = 1;
            }
            if (e0 && ep && en) 
                return vector<int>{};
            for (int p = 0; p < 2; ++p)
                for (int q = 0; q < 2; ++q) {
                    bool ok = 1;
                    if (e0 && p == q) ok = 0;
                    if (ep && p == 0 && q == 1) ok = 0;
                    if (en && p == 1 && q == 0) ok = 0;
                    if (ok) v[k] |= 1 << (p * 2 + q);
                }
            if (!v[k]) 
                return vector<int>{};
        }
        return v;
    };

    auto mc = msk(true), mr = msk(false);
    if (!sz(mc) || !sz(mr)) {
        cout << -1 << '\n';
        return;
    }

    auto go = [&](const vector<int64_t> &c, const vector<int> &m) {
        int s = sz(c);
        vector<array<int64_t, 2>> dp(s, {-1, -1});
        function<int64_t(int, int)> DP = [&](int p, int ant) {
            if (p == s) 
                return int64_t(0);
            int64_t& r = dp[p][ant];
            if (r != -1) 
                return r;
            r = INF;
            for (int cur = 0; cur < 2; ++cur)
                if (!p || (m[p - 1] & (1 << (ant * 2 + cur)))) {
                    int64_t sub = DP(p + 1, cur);
                    if (sub < INF) 
                        r = min(r, sub + (cur ? c[p] : 0));
                }
            return r;
        };
        int64_t ans = INF;
        for (int f = 0; f < 2; ++f) {
            int64_t sub = DP(1, f);
            if (sub < INF) 
                ans = min(ans, sub + (f ? c[0] : 0));
        }
        return ans;
    };

    int64_t col = go(b, mc), fil = go(a, mr);
    cout << (((col >= INF || fil >= INF)) ? -1 : col + fil) << "\n";
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
