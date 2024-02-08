#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ok(vector<ll> a, ll altura, ll mx){
    for(auto x: a){
        mx -= max(0LL, altura - x);
        
        if(mx < 0) {
            return false;
        }
    }
 
    return true;
}

void sol(){
    ll n, mx;
    cin >> n >> mx;

    vector<ll> arr(n);
    for (auto &x: arr) {
        cin >> x;
    }

    ll lo = -1, hi = INT_MAX;
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;

        if (ok(arr, mid, mx)) {
            lo = mid;
        }
        else {
            hi = mid;
        }
    }

    cout << hi - 1 << "\n";
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