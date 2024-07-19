#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll inf = 1E18;
const int maxn = 200010;

ll i, i1, j, k, k1, t, n, m, res, a[maxn], b[maxn], ps[maxn], lo, hi, mid;
bool ok (ll x) {
    // cerr << "x = " << x << nl;
    ll m, p, l;
    m = 0;
    for (i = 0; i <= k; i++) ps[i] = 0;
    for (i = 0; i < n; i++) {
        // cerr << "i = " << i << nl;
        if (x >= b[i]) {
            l = 0; p = a[i];
            while (true) {
                // cerr << "p = " << p << nl;
                if (l >= k - 1) break;
                if (m >= k) return false;
                if (p < b[i]) {
                    m++; ps[l]++; l++; p += (x - b[i]);
                } else {
                    l += (p / b[i]); p %= b[i];
                }
            }
        } else {
            p = a[i];
            if (x == 0) {
                if ((k - 1) * b[i] - p > 0) return false;
                else continue;
            }
            j = ((k - 1) * b[i] - p + x - 1) / x;
            if (j >= k) return false;
            // cerr << "j = " << j << nl;
            for (i1 = k - 1; i1 > k - j - 1; i1--) {
                ps[i1]++; m++;
            }
            if (m >= k) return false;
        }
    }
 
    for (i = 0; i < k; i++) {
        if (i != 0) ps[i] += ps[i - 1];
        // cerr << i << ' ' << ps[i] << nl;
        if (ps[i] > i + 1) return false;
    }
 
    return true;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    lo = 0, hi = inf;
    while (lo != hi) {
        mid = (lo + hi) / 2;
        if (ok(mid)) {
            hi = mid;
        } 
        else {
            lo = mid + 1;
        }
    }
    // cerr << lo << " " << hi << "\n";
    cout << (lo == inf ? -1 : lo) << "\n";

    return 0;
}