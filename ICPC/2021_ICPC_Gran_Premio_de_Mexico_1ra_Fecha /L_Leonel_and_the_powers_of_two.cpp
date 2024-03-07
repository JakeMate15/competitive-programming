#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

string binPow(ll n){
    if (n == 1) return "2";
    if (n % 2) return "(2*" + binPow(n - 1) + ")";
    return "(" + binPow(n / 2) + ")^2";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        ll k;
        cin >> k;
    
        cout << binPow(k) << "\n";
    }

    return 0;
}