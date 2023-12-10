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

    vector<ll> a(n), dp(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll res = 0;
    for(int i = 0; i < n; i++) {
        dp[i] = max(dp[i], a[i]);

        if(a[i] + i < n) {
            dp[a[i] + i] = max(dp[a[i] + i], dp[i] + a[a[i] + i]);
        }
            
        res = max(res, dp[i]);
    }
    
    cout << res << "\n";
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