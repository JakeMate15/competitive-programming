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

    vector<ll> a(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> a[i + 1];
    }

    sort(all(a));
    vector<ll> pref(n + 1);
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }

    ll res = LONG_LONG_MAX;

    for(int i = 1; i <= n; i++) {
        ll c = abs((i - 1) * a[i] - pref[i - 1]) + abs(pref[n] - pref[i] - a[i] * (n - i));
        res = min(res, c);
    }

    cout << res << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}