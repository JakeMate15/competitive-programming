#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

void sol(){
    int n;
    cin >> n;

    map<ll, ll> rep;
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        rep[x]++;
    }

    ll res = 0, sum = 0;
    for(auto [v, r]: rep) {
        if(r >= 3) 
            res += r * (r - 1) * (r - 2) / 6;
        if(r >= 2)
            res += r * (r - 1) / 2 * sum;
        sum += r;
    }

    cout << res << "\n";
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