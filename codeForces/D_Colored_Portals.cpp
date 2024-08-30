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

void sol() {
    int n, q;
    cin >> n >> q;

    vector<string> id(n);
    vector<vector<int>> g(6);
    vector<string> dic = {"BG", "BR", "BY", "GR", "GY", "RY"}; 

    for (int i = 0; i < n; i++) {
        cin >> id[i];
        int p = find(all(dic), id[i]) - dic.begin();
        g[p].push_back(i);
    }

    auto same = [&] (string a, string b) -> bool {
        for (auto x: a) {
            for (auto y: b) {
                if (y == x)
                    return true;
            }
        }

        return false;
    };

    while (q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        if (u > v) {
            swap(u, v);
        }

        if (same(id[u], id[v])) {
            cout << abs(u - v) << "\n";
            continue;
        }

        int res = 1E9;
        for (int i = 0; i < 6; i++) {
            if (dic[i] == id[u] || dic[i] == id[v] || sz(g[i]) == 0) {
                continue;
            }

            auto p = lower_bound(all(g[i]), u);
            if (p != g[i].end()) {
                if (*p <= v) {
                    res = min(res, abs(u - v));
                } else {
                    res = min(res, abs(u - *p) + abs(*p - v));
                }
            } 

            int lo = -1, hi = sz(g[i]);
            while (lo + 1 < hi) {
                int mid = (lo + hi) / 2;

                if (g[i][mid] < u) 
                    lo = mid;
                else 
                    hi = mid;
            }
            if (lo != -1) {
                res = min(res, abs(u - g[i][lo]) + abs(g[i][lo] - v));
            }

        }

        cout << (res == 1E9 ? -1 : res) << "\n";
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