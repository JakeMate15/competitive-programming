#include<bits/stdc++.h>
using namespace std;

#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(int (i)=0; i<n; i++)
#define forr(i,a,n) for(int i=(a); i<n; i++)
#define fore(i,a,n) for(int i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"
#define sz(a)       (int)a.size()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int mod = 1e9+7;

ll binpow(ll a, ll b) {
    if (b == 0)     return 1;
    ll res = binpow(a, b / 2) % mod;

    if (b % 2)      return (res * res * a) % mod;
    else            return (res * res) % mod;
}

void sol(){
    ll n;cin>>n;

    ll res = binpow(2,n);
    debug(res);

}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}