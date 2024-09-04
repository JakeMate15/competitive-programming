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
    int n, q;
    cin >> n >> q;

    ll sum = 0;
    vector<int> arr(n * 2);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i + n] = arr[i];
        sum += arr[i];
    }

    for (int i = 1; i < 2 * n; i++) {
        arr[i] += arr[i - 1];
    }

    RAYA
    debug(arr);
    cerr << '\n';

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        
        int p1 = l / n, p2 = r / n;
        int sep = max(0, p2 - p1 - 1);
        ll res = 0;

        l %= n;
        r %= n;

        // l += p1;
        // r += p2;

        if (p1 == p2) { // Mismo cyclic 
            // if (l > r) {
            //     swap(l, r);
            // }
            res += arr[r] - arr[l - (l == 0 ? 0 : 1)];
            debug("iguales");
        } else {
            r += n;
            res += sep * sum;
            // res += arr[l + n - 1] - arr[l - (l == 0 ? 0 : 1)];
            // res += arr[r] - arr[0];
            res += arr[r] - arr[r - n];
            res += arr[n - 1] - arr[l - (l == 0 ? 0 : 1)];
            debug(r, r - n);
        }

        

        cout << res << "\n";
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