#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {
    ll n;
    cin >> n;

    ll r = ceil(sqrt(n));
    if (r * (r - 1) >= n)
        cout << 2 * r - 1;
    else 
        cout << 2 * r;

    return 0;
}