#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(int (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"

void sol(){
        int n,m,k;
        cin>>n>>m>>k;

        vi a(n+1);
        fore(i,1,n){
                cin>>a[i];
        }

        int res = INT_MAX;
        fore(i,1,n){
                if(i!=m && a[i]<=k && a[i]>0){
                        res = min(res,(int)abs(i-m)*10);
                }
        }

        debug(res);
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}