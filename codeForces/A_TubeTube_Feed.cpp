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
    int n,t;cin>>n>>t;
    vector<int>a(n),b(n);
    forn(i,n){
        cin>>a[i];
        a[i]+=i;
    }
    forn(i,n)   cin>>b[i];

    int iMax=-2,max=-1;
    forn(i,n){
        if(b[i]>max && a[i]<=t){
            max = b[i];
            iMax = i;
        }
    }

    cout << ++iMax << endl;
}

int main(){IO
    int t=1;cin>>t;
    while(t--)  sol();
}