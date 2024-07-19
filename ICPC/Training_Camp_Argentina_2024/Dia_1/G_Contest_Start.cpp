#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {
    int tt;
    cin >> tt;

    while (tt--) {
        ll n, x, t;
        cin >> n >> x >> t;

        ll a = 1LL * (max(0LL, n - t / x)) * (t / x);
        ll b = 1LL * min(n - 1, t / x - 1) * min(n, t / x) / 2;

        cout << a + b << "\n";
    }

    return 0;
}