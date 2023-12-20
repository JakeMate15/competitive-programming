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
    ll l, g;
    cin >> l >> g;

    vector<ll> der, izq;

    ll res = 0;
    for(ll i = 0; i < g; i++) {
        ll pos, dir;
        cin >> pos >> dir;

        if(dir) {
            res = max(res, l - pos);
        }
        else {
            res = max(res, pos);
        }
    }

    cout << res << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}