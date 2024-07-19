#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()

typedef long long ll;

void sol () {
    ll x, y;
    cin >> x >> y;

    ll d = x - y;
    cout << (d == 1 ? "NO" : "YES") << "\n";
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while (t--) {
        sol();
    }

    return 0;
}