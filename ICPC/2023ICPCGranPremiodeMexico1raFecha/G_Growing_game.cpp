//https://codeforces.com/gym/104375/problem/G
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

const int mod = 1e9+7;

void sol(){
    int n;cin>>n;
    vector<int> res(2,1);
    int veces = 2;

    while(res.size()<=5005){
        forn(i,veces)   res.push_back(0);
        forn(i,veces)   res.push_back(1);

        veces++;
    }

    if(res[n])  debug("Jane");
    else        debug("John");
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}