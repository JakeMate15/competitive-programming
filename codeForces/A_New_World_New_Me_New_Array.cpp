#include<bits/stdc++.h>
using namespace std;

void sol () {
    int n, k, p;
    cin >> n >> k >> p;

    if (abs(n) * abs(p) < abs(k)) {
        cout << "-1\n";
        return;
    }

    k = abs(k);
    p = abs(p);

    cout << (k + p - 1) / p << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}