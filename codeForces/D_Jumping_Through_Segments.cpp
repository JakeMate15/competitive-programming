#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

bool interseccion(pair<int, int> a, pair<int, int> b) {
    if(b.first < a.first) {
        swap(a, b);
    }

    if(a.second >= b.first)
        return true;
    return false;
}

bool ok(ll k, vector<pair<int, int>> arr) {
    ll l = 0, r = 0;
    for(int i = 0; i < sz(arr); i++) {
        l = max(l - k, 1LL * arr[i].first);
        r = min(r + k, 1LL * arr[i].second);

        if(l > r)
            return false;
    }
    return true;
}

void sol(){
    // cerr << "================\n";
    int n;
    cin >> n;

    vector<pair<int, int>> a(n + 1);
    ll l = -1LL, r = 0LL;
    a[0] = {0, 0};
    for(int i = 1; i <= n; i++) {
        int l, rr;
        cin >> l >> rr;
        a[i] = {l, rr};
        r = max(r, 1LL * rr);
    }


    r += 10;
    // cerr << l << " " << r << "\n";
    while(l + 1 < r) {
        ll m = (l + r) / 2;
        if(ok(m, a))
            r = m;
        else    
            l = m;
    }

    cout << r << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}