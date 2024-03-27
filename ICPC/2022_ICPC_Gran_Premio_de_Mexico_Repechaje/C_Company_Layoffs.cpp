#include<bits/stdc++.h>
using namespace std;

#define sz(a)   (int)a.size()
#define all(a)  a.begin(), a.end()

typedef long long ll;

int main () {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(all(a));
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = a[i] + pref[i];
    }

    while (q--) {
        int p;
        cin >> p;

        int pos = lower_bound(all(a), p) - a.begin();
        ll sum = pref[pos] + 1LL * (n - pos) * p;

        cout << sum << "\n";
    }
}