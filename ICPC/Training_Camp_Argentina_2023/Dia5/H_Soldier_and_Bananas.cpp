#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(ll (i)=0; i<n; i++)
#define forr(i,a,n) for(ll i=(a); i<n; i++)
#define fore(i,a,n) for(ll i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"

void sol(){
    ll k,n,w;
    cin>>k>>n>>w;
    ll res = k*((w*(w+1))/2)-n;
    if(res<=0)  debug(0);
    else        debug(res);
}
 
int main(){
    IO
    int t=1;
    //cin>>t;
    
    

    while(t--){
        sol();
    }
        
}