#include<bits/stdc++.h>
using namespace std;

const int MX = 2E5 + 5;
const int MOD = 1E9 + 7;

void sol () {
    int n, x;
    cin >> n >> x;

    int s = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s += x;
    }

    cout << (n * x == s ? "YES" : "NO") << "\n";
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