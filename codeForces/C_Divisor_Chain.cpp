#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl              cout << "\n";
typedef long long ll;
typedef long double ld;

bool pot2(ll x) {
    return __builtin_popcountll(x) == 1;
}

void sol(){
    ll n;
    cin >> n;

    vector<ll> res = {n};
    while(!pot2(n)) {
        int tz = __builtin_ctzll(n);
        n -= 1 << tz;
        res.push_back(n);
    }

    while(n > 1) {
        n >>= 1;
        res.push_back(n);
    }

    debln(sz(res));
    for(auto x: res) {
        deb(x);
    }
    nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t=1;
    cin>>t;

    while(t--){
        sol();
    }

    return 0;
}