#include<bits/stdc++.h>
using namespace std;

void sol () {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a == b && c == d && b == c) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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