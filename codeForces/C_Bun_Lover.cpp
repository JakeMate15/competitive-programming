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

lli gaus(lli n){
    return (n*(n+1))/2;
}

void sol(){
    lli n,res;cin>>n;
    res = 4*n+gaus(n-1)+gaus(n-2)+1;
    debug(res);
}

int main(){IO
    int t=1;cin>>t;
    while(t--)  sol();
}


