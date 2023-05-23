#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(lli (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)

void sol(){
    int n;
    cin>>n;
    int a[n];

    forn(i,n)   cin>>a[i];

    int par=0,impar=0;
    forn(i,n){
        if(a[i]%2==0)   par+=a[i];
        else    impar+=a[i];
    }

    if(par>impar)   cout << "YES"<<endl;
    else    cout<<"NO" << endl;
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}