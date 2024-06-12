#include<bits/stdc++.h>
using namespace std;

#define sz(a)   (int) a.size()
#define all(a)  a.begin(), a.end()

typedef long long ll;
typedef pair<int, int> pi;

int main () {
    int n;
    cin >> n;

    vector<int> c(n), p(n);
    for (auto &x: c)
        cin >> x;
    for (auto &x: p)
        cin >> x;

    auto ok = [&] (ll x) -> bool {
        ll xd = 0;
        for (int i = 0; i < n; i++) {
            xd += p[i];
            if (xd < x * c[i])
                return false;
            xd -= x * c[i];
        }

        return true;
    };

    ll lo = 0, hi = 2e9;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        
        if (ok(mid))
            lo = mid + 1;
        else
            hi = mid - 1;
    }

    cout << hi;
}