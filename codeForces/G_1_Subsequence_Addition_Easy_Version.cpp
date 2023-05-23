#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(lli (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)

void sol(){
    int n;cin>>n;
    int a[n];

    forn(i,n)   cin>>a[i];
    sort(a,a+n);
    if(a[0]!=1){
        cout << "NO\n";
        return;
    }
    int obj=1;
    forr(i,1,n){
        if(a[i]>obj){
            cout << "NO\n";
            return;
        }
        obj+=a[i];
    }

    cout << "YES\n";
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}