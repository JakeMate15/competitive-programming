#include<bits/stdc++.h>
using namespace std;

void sol () {
    int n;
    cin >> n;

    vector<int> p(n), s(n);
    for (auto &x: p) {
        cin >> x;
    }
    for (auto &x: s) {
        cin >> x;
    }

    if (p[n - 1] != s[0]) {
        cout << "NO\n";
        return;
    }

    bool ok = true;
    for (int i = 1; i < n && ok; i++) {
        if (p[i - 1] % p[i] != 0) 
            ok = false;
        if (s[i] % s[i - 1] != 0) 
            ok = false;
    }
        
    int g = p[n - 1];
    for (int i = 1; i < n && ok; i++) {
        int x = p[i - 1] / p[i];
        int y = s[i] / g;
        if (gcd(x, y) != 1)
            ok = false;
        
        x = p[i] / g;
        y = s[i] / s[i - 1];
        if (gcd(x, y) != 1) 
            ok = false;
    }

    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}