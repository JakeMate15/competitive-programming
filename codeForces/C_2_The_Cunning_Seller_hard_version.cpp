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

vector<int64_t> pot(40, 1);

int64_t get(int64_t n) {
    int64_t s = 0;
    while(n) { s += n % 3; n /= 3; }
    return s;
}

void sol () {
    int n, k;
    cin >> n >> k;

    if(k < get(n)) {
        cout << -1 << "\n";
        return;
    }

    int64_t d = max(0, n - k);
    int64_t mn = (d + 1) / 2;

    int64_t extra = 0, rem = mn;
    for(int i = 0; rem > 0; i++) {
        int64_t disp = n / pot[i+1];
        int64_t tk = min(rem, disp);
        extra += tk * pot[i];
        rem -= tk;
    }

    cout << 3LL * n + extra << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 1; i < 40; i++) 
        pot[i] = pot[i - 1] * 3;

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}
