#include<bits/stdc++.h>

#define endl '\n'
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

#define pb push_back

#define all(v) v.begin(), v.end()
#define sortall(f) sort(all(f))

#define forn(i,n) for(ll i=0;i<n;i++)

const int MX = 1e9;

using namespace std;

typedef long long ll;

bool ok(ll w, ll h, ll n, ll size){
    return ((size/w)*(size/h))>=n;
}

int main(){IO
    ll w,h,n,l,r,m;
    cin>>w>>h>>n;
    l = 0;
    r = 1;
    while(!(ok(w,h,n,r)))   r*=2;
    //cout << "r vale " << r << "\n";

    while(r>l+1){
        m = l+(r-l)/2;
        if(ok(w,h,n,m)) r = m;
        else    l = m;
    }

    cout << r << "\n";
    return 0;
}