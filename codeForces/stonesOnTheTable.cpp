#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(lli (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)

void sol(){
    int n;string s;cin>>n>>s;
    int res=0;
    forn(i,n-1){
        if(s[i] == s[i+1])  res++;
    }
    cout << res << "\n";
}

int main(){IO
    int t=1;//cin>>t;
    while(t--)  sol();
}