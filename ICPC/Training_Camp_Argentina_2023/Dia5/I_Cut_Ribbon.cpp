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

void sol(){
        int n;
        vi nc(3);
        cin>>n;
        forn(i,3)
                cin>>nc[i];
        
        vi dp(n+1);
        dp[0] = 0;
        fore(i,1,n)
                dp[i] = INT_MIN;
        
        fore(i,1,n){
                for(int c: nc){
                        if(i-c>=0){
                                dp[i] = max(dp[i],dp[i-c]+1);
                        }
                }
        }

        debug(dp[n]);
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}
