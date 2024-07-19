#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a)   (int) a.size()

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<vector<ll>> vvi;

int main () {
    ll n, h;
    cin >> n >> h;

    vector<int> arr(n);
    for (auto &x: arr) {
        cin >> x;
    }

    auto ok = [&] (int m) -> bool {
        vector<int> a(m);
        for (int i = 0; i < m; i++) {
            a[i] = arr[i];
        }

        sort(rall(a));

        ll ch = 0;
        for (int i = 0; i < m; i += 2) {
            ch += a[i];
        }

        return ch <= h;
    };

    for (int i = 0; i <= n; i++) {
        if (!ok(i)) {
            cout << max(0, i - 1);
            return 0;
        }
    }

    cout << n;

    return 0;
}