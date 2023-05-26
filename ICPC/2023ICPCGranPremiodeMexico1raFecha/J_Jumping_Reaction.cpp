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

const int MAXN = 1e6 + 10;
const ll MOD = 1e9 + 7;
const ll HALF = (MOD + 1)/2;
ll a[MAXN], s[MAXN], sq[MAXN];

void sol() {
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        s[i] = (s[i - 1] + x) % MOD;
        sq[i] = (sq[i - 1] + x * x) % MOD;
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        ll sum = (s[r] - s[l - 1]) % MOD;
        ll sumsq = (sq[r] - sq[l - 1]) % MOD;
        ll ans = (sum * sum - sumsq) % MOD;
        ans = (ans * HALF) % MOD;
        debug((ans + MOD) % MOD);
    }
}


int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}