#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n, mx;
    cin >> n >> mx;

    set<ll> st;
    ll x;
    for (int i = 0; i < n; i++) {
        cin >> x;

        for (int j = 2; j * j <= x; j++) {
            if (x % j == 0) {
                st.insert(j);
                st.insert(x / j);
            }
        }
    }

    // for (auto x: st) {
    //     cerr << x << " ";
    // }

    set<ll> res;
    for (auto x: st) {
        for (int i = 1; x * i <= mx; i++) {
            res.insert(x * i);
        }
    }

    for (auto x: res) {
        cerr << x << " ";
    }

    cout << res.size();
}