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

void sol () {
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<int64_t> a(n), b(m);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    for (int i = 0; i < m; i++) 
        cin >> b[i];
    
    sort(rall(a));
    sort(rall(b));
    
    vector<int64_t> prefA(n + 1, 0), prefB(m + 1, 0);
    for (int i = 0; i < n; i++) 
        prefA[i + 1] = prefA[i] + a[i];
    for (int i = 0; i < m; i++) 
        prefB[i + 1] = prefB[i] + b[i];

    auto val = [&](int s, int z) -> int64_t {
        return prefA[s] + prefB[z - s];
    };
    auto incA = [&](int idx) -> int64_t {
        return (1 <= idx && idx <= n) ? a[idx - 1] : (int64_t)-4E18;
    };
    auto incB = [&](int idx) -> int64_t {
        return (1 <= idx && idx <= m) ? b[idx - 1] : 0LL;
    };

    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        
        int L = max(0, z - y);
        int R = min(x, z);
        if (L == R) {
            cout << val(L, z) << "\n";
            continue;
        }

        int l = max(L, 1), r = R, pos = l - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int64_t delta = incA(mid) - incB(z - mid + 1);
            if (delta >= 0) {
                pos = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        int64_t ans = val(L, z);
        if (pos >= L) {
            ans = max(ans, val(pos, z));
        }
        ans = max(ans, val(R, z));
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}
