#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()
#define sz(a)   (int) a.size()

typedef long long ll;
typedef pair<ll, int> ii;

const int mx = 5e6 + 5;

ll divT (ll x, ll y) {
    if (y < 0) {
        y = -y;
        x = -x;
    }
    if (x <= 0)
        return x / y;
    return (x - 1) / y + 1;
}

int main () {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n), b(n);
    for (auto &x: a) {
        cin >> x;
    }
    for (auto &x: b) {
        cin >> x;
    }

    multiset<ii> st;
    for (int i = 0; i < n; i++) {
        ll tiempo = divT(a[i], b[i]);
        cerr << tiempo << "\n";
        ll consumo = tiempo * b[i];

        if (a[i] - consumo < k)
            st.emplace(a[i] - consumo, b[i]);
        // cerr << a[i] << " " << b[i] << " " << tiempo << "\n";
        // st.emplace();
    }

    for (auto [a, b]: st) {
        cerr << a << " " << b << "\n";
    }

    return 0;
}