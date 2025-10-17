#include<bits/stdc++.h>
using namespace std;

void sol () {
    int n;
    cin >> n;
    
    int sq = sqrt(n);
    if (sq * sq == n) {
        cout << sq << " " << 0 << "\n";
    } else {
        cout << "-1\n";
    }
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