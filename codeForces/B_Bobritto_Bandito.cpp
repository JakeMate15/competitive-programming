#include<bits/stdc++.h>
using namespace std;

void sol () {
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    cout << min(r, m) - m << " " << min(r, m) << "\n";
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