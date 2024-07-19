#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()

typedef long long ll;

void sol () {
    int n;
    string s;

    cin >> n >> s;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        if (int (s[i] - '0') % 2 == 0) {
            res += (i + 1);
        }
    }

    cout << res << "\n";
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;

    while (t--) {
        sol();
    }

    return 0;
}