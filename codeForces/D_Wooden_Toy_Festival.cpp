#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(lli (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"

bool ok(int m, vi a, int n){
    int i = 0;
    while (i + 1 < n && a[i + 1] - a[0] <= 2 * m) {
        ++i;
    }
    int j = n - 1;
    while (j - 1 >= 0 && a.back() - a[j - 1] <= 2 * m) {
        --j;
    }
    ++i; --j;

    if( i>j || a[j]-a[i]<=2*m ) return true;

    return false;
}

void sol(){
    int n;cin>>n;

    vector<int> a(n);
    for(int &x: a)  cin>>x;

    sort(all(a));

    int l=-1,r=1e9,m;
    while(l+1<r){
        m=l+(r-l)/2;
        if( ok(m,a,n) ) r=m;
        else            l=m;
    }

    debug(r);
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}