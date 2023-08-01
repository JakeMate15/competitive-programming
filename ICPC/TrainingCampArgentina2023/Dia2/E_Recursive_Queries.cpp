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

const int mx = 1e6+5;
int dp[mx];
vi st[10];

int f(int n){
        int mult = 1;
        while(n>0){
                if(n%10)
                        mult*=n%10;
                n/=10;
        }
        return mult;
}

int g(int n){
        if(n<10)
                return n;
        
        int &mem = dp[n];

        if(mem!=-1)
                return mem;

        return mem=g(f(n));
}

void sol(){
        int l,r,k;
        cin>>l>>r>>k;

        int res = upper_bound(all(st[k]),r) - lower_bound(all(st[k]),l);
        debug(res);
}

int main(){IO
        memset(dp,-1,sizeof(dp));

        fore(i,1,1e6){
                st[g(i)].push_back(i);
        }

        int t=1;
        cin>>t;
        while(t--)  sol();
}