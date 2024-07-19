#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()

typedef long long ll;
typedef pair<int, int> ii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    sort(all(a));
    int res = 1;
    vector<ll> r;
    for (int i = 0; i < n; i++) {
        // r = {a[i]};
        for (int pot = 0; pot <= 32; pot++) {
            ll t = (1LL << pot);
            ll valor = a[i];
            if (binary_search(all(a), valor + t)) {
                res = max(res, 2);
                if (res == 2) {
                    r = {valor, valor + t};
                }
                
                if (binary_search(all(a), valor + 2 * t)) {
                    res = 3;
                    r = {valor, valor + t, valor + 2 * t};
                }
            }
        }
    }

    if (res == 1) {
        r = {a[0]};
    }
    cout << sz(r) << "\n";
    for (auto x: r) {
        cout << x << " ";
    }

    return 0;
}