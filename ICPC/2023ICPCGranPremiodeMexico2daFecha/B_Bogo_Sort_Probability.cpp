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
    fore(i,1,N) fac[i] = (fac[i-1]*i)%MOD;
}

ll extendedEuclidean(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }

    ll x1, y1;
    ll gcd = extendedEuclidean(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;

    return gcd;
}

ll modularInverse(ll a, ll m) {
    ll x, y;
    ll gcd = extendedEuclidean(a, m, x, y);

    if (gcd != 1)   return -1;
    else            return (x % m + m) % m;
}

int invMod(int a, int b){
    int inversoModularB = modularInverse(b, MOD);
    if (inversoModularB == -1)  return -1;
    else                        return  (a * inversoModularB) % MOD;
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

    debug(invMod(fac[n-rep.size()+1],fac[n]));
    while(k--){
        int A,B;
        cin>>A>>B;A--;

        int keyR = a[A];
        if(keyR!=B){
            if(rep.count(B))    rep[B]++;
            else                rep[B]=1;

            if(rep[keyR]>1)     rep[keyR]--;  
            else                rep.erase(keyR);     
            a[A] = B;
        }
        rep.erase(0);
        debug(invMod(fac[n-rep.size()+1],fac[n]));

    }
}