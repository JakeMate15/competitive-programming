#include<bits/stdc++.h>
using namespace std;

#define sz(a)   (int) a.size()
#define all(a)  a.begin(), a.end()

typedef long long ll;

int main () {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(all(a));
    sort(all(b));
    reverse(all(b));

    set<ll> difs;
    for (int i = 0; i < n; i++) {
        difs.insert(1LL * a[i] + b[i]);
    }

    ll res = 1LL * *prev(difs.end()) - *difs.begin();
    cout << res << "\n";
}