#include<bits/stdc++.h>
using namespace std;

#define forn(i,n)       for(int i=0; i<n; i++)
#define forr(i,a,n)     for(int i=a; i<n; i++)
#define fore(i,a,n)     for(int i=a; i<=n; i++)
#define fornd(i,n)      for(int i=n; i>=0; i--)
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define pb              push_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const int mod = 1e9+7;
const int mx = 1e6+5;
int dp[mx];

int sol(int n){
    if(n<0)     return 0;
    if(n<=1)    return 1;

    int &mem = dp[n];
    if(mem != 0)   return mem;

    fore(i,1,6){
        (mem+=sol(n-i))%=mod;
    }

    return mem;
}

void sol(){
    int n;
    cin>>n;

    //debln(sol(n));
    dp[0] = dp[1] = 1;
    fore(i,2,n){
        fore(j,1,6){
            if(i-j<0)   break;
            (dp[i]+=dp[i-j])%=mod;
        }
    }
    debln(dp[n]);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int t=1;
    //cin>>t;
    while(t--){
        sol();
    }

    return 0;
}