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
    
    if(n==1)        cout << "1\n";
    else if(n&1)    cout << "-1\n";
    else{
        for(int i=n; i>=1; i-=2)    
            cout << i << " " << n+1-i << " ";
        cout << endl;
    }
}

int main(){IO
    int t=1;cin>>t;
    while(t--)  sol();
}
