#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
void sol() {
    ll n;
    cin >> n;

    while (n >= 100 && (n % 10 >= 0 && n % 10 <= 8)) {
        n /= 10;
        n--;
    }

    cout << (n >= 10 && n <= 18 ? "YES" : "NO") << "\n";
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