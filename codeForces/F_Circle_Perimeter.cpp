#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()
#define sz(a)   (int)a.size()

typedef int64_t ll;

vector<ll> rs, sq; 

void sol () {
    ll d;
    cin >> d;

    ll l = d * d, r = d * d + 2 * d + 1, res = 0;
    for (int i = 0; i <= sz(sq) && sq[i] < r; i++) {
        ll c1 = sq[i];
        ll c2 = l - c1;

        auto cnt1 = lower_bound(all(sq), c2) - sq.begin();
        
        c2 = r - sq[i];
        auto cnt2 = lower_bound(all(sq), c2) - sq.begin();

        res += (cnt2 - cnt1);
    }

    cout << (res - 1) * 4 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    ll mx = 1e5 * 1e5 + 2 * 1e5 + 1;
    for (ll i = 0; i * i <= mx; i++) {
        sq.push_back(i * i);
        rs.push_back(i);
    }

    while(t--) {
        sol();
    }

    return 0;
}

