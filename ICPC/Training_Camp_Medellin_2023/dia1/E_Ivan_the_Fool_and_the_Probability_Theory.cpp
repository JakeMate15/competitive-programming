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

const int N = 1e5+10, mod = 1e9+7;

void sol(){
    int n, m, f[N];
    cin >> n >> m;

    f[0] = f[1] = 1;
    forr (i, 2, N)    
        f[i] = (f[i-1] + f[i-2]) % mod;

    debug(2ll * (f[m] + f[n] - 1) % mod );
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}