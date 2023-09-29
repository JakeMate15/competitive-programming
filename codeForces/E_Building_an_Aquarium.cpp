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

bool ok(ll altura, vector<ll> a, ll mx){
    for(auto x: a){
        mx-=(max(0LL,altura-x));
        
        if(mx<0) {
            return false;
        }
    }

    return true;
}

void sol(){
    int n,k;
    cin>>n>>k;

    vector<ll> a(n);
    forn(i,n) {
        cin>>a[i];
    }

    ll l = -1, r = INT_MAX;
    while(l+1<r){
        ll m = (l+r)/2;

        if(ok(m,a,k))   l = m;
        else            r = m;

    }

    debln(r-1);


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