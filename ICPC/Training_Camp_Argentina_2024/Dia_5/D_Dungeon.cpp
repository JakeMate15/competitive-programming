#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {
    int tt = 1;
    cin >> tt;

    while (tt--) {
        ll a, b, c;
        cin >> a >> b >> c;

        ll s = a + b + c;
        if (s % 9)
            cout << "NO\n";
        else if (min({a, b, c}) >= s / 9)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}