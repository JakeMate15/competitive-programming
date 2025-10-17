#include<bits/stdc++.h>
using namespace std;

void sol () {
    int a, b;
    cin >> a >> b;

    if (a == b) 
        cout << 0 << "\n";
    else if (a % b == 0 || b % a == 0) 
        cout << 1 << "\n";
    else 
        cout << 2 << "\n";
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