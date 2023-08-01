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
        cin>>n;

        vi a(n),suff(n);

        for(auto &x: a){
                cin>>x;
        }

        suff[n-1] = a[n-1];
        for(int i=n-2; i>=0; i--){
                suff[i] = suff[i+1] + a[i];
        }

        //for(auto x: suff)       cout << x << " ";
        vi dp(n);
        dp[n-1] = a[n-1];
        for(int i=n-2; i>=0; i--){
                dp[i] = max(dp[i+1], suff[i+1]+a[i]-dp[i+1]);
        }
        cout << suff[0]-dp[0] << " " << dp[0];
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}