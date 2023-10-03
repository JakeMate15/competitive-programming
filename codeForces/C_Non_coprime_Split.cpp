#include<bits/stdc++.h>
using namespace std;

#define forn(i,n)       for(int i=0; i<n; i++)
#define forr(i,a,n)     for(int i=a; i<n; i++)
#define fore(i,a,n)     for(int i=a; i<=n; i++)
#define fornd(i,n)      for(int i=n; i>=0; i--)
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define pb              push_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;


//gcd(a, l - a) = gcd(a, l)
//gcd(a, l + a) = gcd(a, l)

ll divisor_min(ll x) {
    for(ll i = 2; i * i <= x; i++) {
        if(x % i == 0) {
            return i;
        }
    }
    
    return x;
}

void sol(){
    ll l, r;
    cin >> l >> r;

    for(int i = max(l,4 * 1LL); i <= r; i++) {
        ll mn = divisor_min(i);
        if(mn != i) {
            deb(i - mn); debln(mn);
            return;
        }
    }

    debln(-1);
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