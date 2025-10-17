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

vector<int64_t> pots(30, 1), c(25, 0);

void sol () {
    int n;
    cin >> n;

    int64_t ans = 0;
    int pos = 0;
    while (n) {
        int d = n % 3;
        n /= 3;
        ans += d * c[pos++];
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; i < 30; i++) {
        pots[i] = pots[i - 1] * 3;
    }
    c[0] = 3;
    for (int i = 1; i < 25; i++) {
        c[i] = pots[i + 1] + 1LL * i * pots[i - 1];
    }

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}