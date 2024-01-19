#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

ll binPow(ll x, ll n, ll m) {
    ll res = 1;
    
    while (n > 0) {
        if (n & 1)
            res = res * x;
        x = x * x;
        n >>= 1;
    }   
    
    return res;
}

void sol(){
    int n;
    cin >> n;

    int c = 1;
    for(int p = 9;; n -= p, c++, p = 9 * binPow(10, c - 1, mod) * c) {
        if(n - p <= 0)  break;
    }

    n--;
    int x = n / c;
    int y = n % c;

    int res = binPow(10, c - 1, mod) + x;
    string r = to_string(res);
    cout << r[y] << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}