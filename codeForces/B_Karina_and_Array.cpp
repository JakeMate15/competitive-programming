#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(lli (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"

void sol(){
    int n;cin>>n;
    lli a[n];
    forn(i,n)   cin>>a[i];

    sort(a,a+n);
    cout << max(a[0]*a[1],a[n-1]*a[n-2]) << endl;
}

int main(){IO
    int t=1;cin>>t;
    while(t--)  sol();
}