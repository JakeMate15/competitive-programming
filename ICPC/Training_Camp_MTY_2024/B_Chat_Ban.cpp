#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()
#define sz(a)   (int)a.size()
typedef long long ll;

const int mod = 1e9 + 7;

void solve() {
    ll k, x;
    cin >> k >> x;
    
    if (x <= k * (k + 1) / 2) {
        ll t = sqrt(x * 2) - 1;
        while (t * (t + 1) / 2 < x) {
            t++;
        }
        cout << t << '\n';
    } else {
        x -= k * (k + 1) / 2;
        if (x >= k * (k - 1) / 2) {
            cout << 2 * k - 1 << '\n';
            return;
        }
        ll t = k - 2 - sqrt(k * (k - 1) - x * 2);
        while (t < 0 || t * (k - 1 + k - t) / 2 < x) {
            t++;
        }
        cout << k + t << '\n';
    }
}

int main() {    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}