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


int main(){IO
    int n,k;cin>>n>>k;
    int a[n][n];
    forn(i,n)   forn(j,n)   cin>>a[i][j];

    int res = 0;
    for(int i=0; i<n-k+1; i++){
        for(int j=0; j<n-k+1; j++){
            if( a[i][j]==a[i+k-1][j] && a[i][j]==a[i][j+k-1] && a[i][j]==a[i+k-1][j+k-1])   res++;
        }
    } 

    debug(res);
}
