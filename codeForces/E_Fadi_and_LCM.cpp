#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void sol(){
    ll x;
    cin >> x;

    ll l = 1, r = x;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            ll a = i;
            ll b = x / i;
            if (gcd(a, b) == 1) {
                l = a, r = b;
            }
        }
    }

    cout << l << " " << r << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;

    while(t--){
        sol();
    }

    return 0;
}