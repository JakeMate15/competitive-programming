#include<bits/stdc++.h>
using namespace std;

void sol () {
    int x;
    cin >> x;

    int msb = log2(x);
    int msk = x & ~(1 << msb);
    for (int i = 0; i < msb; i++) {
        int y = msk ^ (1 << i);
        if (x > y && y > (x & y) && (x & y)) {
            cout << y << "\n";
            return;
        }
    }
    
    cout << -1 << "\n";
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