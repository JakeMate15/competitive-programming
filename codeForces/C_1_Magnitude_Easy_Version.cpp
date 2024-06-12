#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const ll MX = -180000000005;
 
void sol() {
    // cerr << "===============\n";
    int n;
    cin >> n;

    vector<ll> a(n);
    vector<vector<ll>> dp(n, vector<ll>(2, MX));

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    function<ll(int, int)> go = [&] (int i, int op) -> ll {
        if (i < 0)
            return 0LL;

        // cerr << "Entramos: " << i << " " << op << "\n";
        ll &mem = dp[i][op];
        if (mem != MX) {
            // cerr << "Salimos: " << i << " " << op << " con " << mem << "\n";
            return mem;
        }

        ll r1, r2;
        if (!op) {
            r1 = abs(go(i - 1, 0) + a[i]);
            r2 = abs(go(i - 1, 1) + a[i]);
        }
        else {
            r1 = go(i - 1, 0) + a[i];
            r2 = go(i - 1, 1) + a[i];
        }

        // cerr << "Salimos: " << i << " " << op << " con " << max(r1, r2) << "\n";
        return mem = max(r1, r2);
    };


    cout << go(n - 1, 0) << "\n";
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}