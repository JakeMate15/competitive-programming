#include<bits/stdc++.h>

#define endl '\n'
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define YES cout<<"Yes\n";
#define NO cout<<"No\n";
#define pb push_back
#define all(v) v.begin(), v.end()
#define sortall(f) sort(all(f))
#define forn(i,n) for(ll i=0;i<n;i++)

const int MX = 1e7;

using namespace std;

typedef long long ll;

int n,k,a[MX];

bool ok(double x){
    int sum=0;
    forn(i,n){
        sum+=floor(a[i]/x);
    }
    return sum>=k;
}

int main(){IO
    cin>>n>>k;
    forn(i,n)   cin>>a[i];

    double l = 0,r=1e8,m;
    forn(i,100){
        m = l+(r-l)/2;
        if(ok(m))   l=m;
        else    r = m;
    }

    cout << setprecision(20) << l << "\n";

    return 0;
}