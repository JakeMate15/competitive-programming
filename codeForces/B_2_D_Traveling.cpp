#include<bits/stdc++.h>
using namespace std;
 
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl              cout << "\n";
typedef long long ll;

void sol(){
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    a--, b--;

    vector<ll> x(n), y(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    ll res = abs(x[a] - x[b]) + abs(y[a] - y[b]);
    
    ll aa = 1e18, bb = 1e18;
    for(int i = 0; i < k; i++) {
        aa = min(1LL * abs(x[a] - x[i]) + 1LL * abs(y[a] - y[i]), aa);
        bb = min(1LL * abs(x[i] - x[b]) + 1LL * abs(y[i] - y[b]), bb);
    }

    debln(min(res, aa + bb));
    
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int t=1;
    cin>>t;
    while(t--){
        sol();
    }

    return 0;
}