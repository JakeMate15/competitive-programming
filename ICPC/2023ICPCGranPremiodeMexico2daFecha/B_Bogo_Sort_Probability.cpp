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

const int N = 1e6;
const int MOD = 1e9+7;
int fac[N+5] = {1};

void calcF(){
    fore(i,1,N) fac[i] = (fac[i-1]*i);
}

pair<ll,ll> extendedEuclid (ll a, ll b){ //a * x + b * y = gcd(a,b)
    ll x,y;
    if (b==0) return {1,0};
    auto p=extendedEuclid(b,a%b);
    x=p.second;
    y=p.first-(a/b)*x;
    if(a*x+b*y==-gcd(a,b)) x=-x, y=-y;
    return {x,y};
}

ll inv(ll a, ll mod) { //inverse of a modulo mod
    assert(gcd(a,mod)==1);
    pair<ll,ll> sol = extendedEuclid(a,mod);
    return ((sol.first%mod)+mod)%mod;
}


int main(){IO
    int n,k;
    cin>>n>>k;

    int a[n];
    map<int,int> rep;
    forn(i,n){
        cin>>a[i];
        if(rep.count(a[i])) rep[a[i]]++;
        else                rep[a[i]]=1;
    }

    calcF();

    int q = 1;
    for(auto x: rep){
        (q*=fac[x.second]);
    }
    debug( ((q * inv(fac[n],MOD))+MOD)%MOD );
    while(k--){
        int A,B;
        cin>>A>>B;A--;

        int keyR = a[A];
        if(keyR!=B){
            if(!rep.count(B))   rep[B]=0;
            if(rep[keyR]==0)    (q/=1);
            else                (q/=rep[keyR]);
            rep[keyR]--;
            rep[B]++;
            (q*=rep[B]);
            a[A] = B;
        }

        debug( ((q * inv(fac[n],MOD))+MOD)%MOD );

    }
}