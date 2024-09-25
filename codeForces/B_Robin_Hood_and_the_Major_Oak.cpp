#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void sol () {
    ll n, k;
    cin >> n >> k;

    ll pa = (n + 1) / 2 - max(1LL, n - k + 1) / 2;

    if (pa & 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}