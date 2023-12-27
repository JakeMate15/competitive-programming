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
    ll n, k;
    cin >> n >> k;

    vector<ll> res;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            res.push_back(i);
            if(i * i < n) {
                res.push_back(n / i);
            }
        }
    }

    sort(all(res));

    if(sz(res) < k) {
        cout << "-1\n";
    }
    else {
        cout << res[k - 1] << "\n";
    }
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