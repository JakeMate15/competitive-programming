#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()

typedef long long ll;

int main () {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    sort(all(a));

    ll res = 0;
    for (int i = 0; i < n - 1; i++) {
        res += (a[i] + (i + 1) * a[i]);
    }

    cout << res + n * (a.back()) << "\n";

    return 0;
}