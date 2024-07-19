#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {
    int tt;
    cin >> tt;

    while (tt--) {
        ll n;
        cin >> n;

        set<ll> res;
        for (ll i = 1; i * i <= n; i++) 
            res.insert(i * i);
        for (ll i = 1; i * i * i <= n; i++) 
            res.insert(i * i * i);

        cout << res.size() << "\n";
    }

    return 0;
}