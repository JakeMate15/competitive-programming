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

void sol () {
    int k;
    cin >> k;

    vector<int> cnt(k + 5);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    int n, m;
    for (ll i = 1; i * i <= k - 2; i++) {
        int d1 = -1, d2 = -1;
        if ((k - 2) % i == 0) {
            d1 = i;
            d2 = (k - 2) / d1;
            
            if (d1 == d2 && cnt[d1] >= 2) {
                cout << d1 << " " << d1 << "\n";
                return;
            } else if (d1 != d2 && cnt[d1] && cnt[d2]) {
                cout << d1 << " " << d2 << "\n";
                return;
            }
        }
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