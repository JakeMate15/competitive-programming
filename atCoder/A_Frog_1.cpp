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

void sol(){
    int n;
    cin>>n;
    
    vector<ll> a(n),dp(n,0);
    forn(i,n){
        cin>>a[i];
        if(i)   dp[i]=INT_MAX;
    }

    forr(i,1,n){
        fore(j,1,2){
            if(i-j>=0){
                dp[i] = min( abs(a[i]-a[i-j])+dp[i-j] , dp[i] );
            }
        }
    }

    debln(dp[n-1]);
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