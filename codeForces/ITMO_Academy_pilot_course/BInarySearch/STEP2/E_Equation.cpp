#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define YES cout<<"Yes\n";
#define NO cout<<"No\n";
#define pb push_back
#define all(v) v.begin(), v.end()
#define sortall(f) sort(all(f))
#define forn(i,n) for(ll i=0;i<n;i++)

typedef long long ll;
typedef long double ld;

const int MX = 2*1e8;

bool ok(ld x, ld c){
    return (x*x+sqrt(x)) > c;
}

int main(){IO
    double c;cin>>c;
    double l=0.0, r=INT_MAX,m;

    forn(i,100){
        m = l+(r-l)/2;
        if(ok(m,c)) r = m;
        else    l = m;
    }

    cout << setprecision(20) << l << "\n";

    return 0;
}