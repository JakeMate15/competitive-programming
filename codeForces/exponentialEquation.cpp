#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(lli (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)

void sol(){
    int n;cin>>n;
    if(n&1) cout << -1 << endl;
    else    cout << 1 << " " << n/2 << endl;
}

int main(){IO
    int t=1;cin>>t;
    while(t--)  sol();
}