#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
string s, h = "hard";
vector<ll> c;
ll inf = 1e18;
vector<vector<ll>> dp;

ll go (int i, int j) {
    if (j == 4) 
        return inf;

    if (i == n) 
        return 0;

    ll &res = dp[i][j];
    if (res != inf)
        return res;

    if (s[i] == h[j]) {
        ll r1 = go(i + 1, j) + c[i];
        ll r2 = go(i + 1, j + 1);
        
        res = min(r1, r2);

        // cerr << "Coinciden en " << i << " " << j << "\n";
        // cerr << s[i] << " " << h[j] << "\n";
        // cerr << r1 << " " << r2 << "\n";
        // cerr << c[i] << "\n";
        // cerr << "\n\n\n";
    }    
    else {
        res = min(res, go(i + 1, j));
    }

    return res;
}

int main () {
    ios::sync_with_stdio(0);
    cout.tie(0);

    cin >> n >> s;

    c.resize(n);
    for (auto &x: c) {
        cin >> x;
    }

    int i = 0;
    for (auto x: s) {
        if (i < 5 && x == h[i]) {
            i++;
        }
    }

    if (i < 4) {
        cout << 0;
        return 0;
    }

    dp = vector<vector<ll>>(n + 5, vector<ll>(4, inf));
    cout << go(0, 0) << "\n";


    return 0;
}