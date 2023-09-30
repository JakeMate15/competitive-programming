#include<bits/stdc++.h>
using namespace std;
 
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl()            cout << "\n"

typedef long long ll;

const int mod = 998244353;

void sol(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    for(int b = 0; b < 30; b++) {
        ll cb = 1LL << b;

        ll cnt[2];
        cnt[0] = 1;
        cnt[1] = 0;
        
        ll sum[2];
        sum[0] = sum[1] = 0;

        ll curr = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] & cb) {
                curr ^= 1;
            }

            cnt[curr]++;
            sum[curr] += i + 1;

            ll cv = cnt[curr ^ 1] * (i + 1) - sum[curr ^ 1];
            cv %= mod;

            ans += cv * cb;
            ans %= mod;
        }
    }

    debln(ans);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int t=1;
    //cin>>t;
    while(t--){
        sol();
    }

    return 0;
}