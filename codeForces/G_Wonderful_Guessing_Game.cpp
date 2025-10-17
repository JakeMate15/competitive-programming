#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include "/algoDebug.h"
#else
    #define debug(x...)
    #define RAYA
    #define raya
#endif

#define sz(a)    (int)(a).size()
#define all(a)   (a).begin(), (a).end()
#define rall(a)  (a).rbegin(), (a).rend()

const int MX = 2e5 + 5;
int pos[MX], blk[MX];

void sol() {
    int n;
    cin >> n;

    int q = 1;
    int64_t pw = 1;
    while (1LL * q * pw < n) {
        q++;
        pw *= 3;
    }

    for (int x = 1; x <= n; ++x) {
        int64_t idx = x - 1;
        pos[x] = idx % q;
        blk[x] = idx / q;
    }

    cout << q << "\n";
    for (int j = 0; j < q; ++j) {
        vector<int> a;
        for (int x = 1; x <= n; ++x) {
            if (pos[x] == j) continue;
            int d = blk[x] % 3;
            if (d != 0) {
                a.push_back(x);
            }
        }
        cout << sz(a);
        for (int v : a) {
            cout << ' ' << v;
        }
        cout << "\n";
    }
    cout << flush;

    string s;
    cin >> s;

    int p = 0;
    while (p < q && s[p] != '?') {
        ++p;
    }

    int64_t b = 0;
    for (int j = 0; j < q; ++j) {
        if (j == p) continue;
        b = b * 3 + (s[j] == 'L' ? 1 : (s[j] == 'R' ? 2 : 0));
    }

    int64_t ans = b * (int64_t)q + p + 1;
    cout << ans << "\n" << flush;
}


int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}
