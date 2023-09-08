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
vector<int> f(N);

void calcF(){
    fore(i,1,N) fac[i] = (fac[i-1]*i);
}

int factmod(int n, int p) {
    vector<int> f(p);
    f[0] = 1;
    for (int i = 1; i < p; i++)
        f[i] = f[i-1] * i % p;

    int res = 1;
    while (n > 1) {
        if ((n/p) % 2)
            res = p - res;
        res = res * f[n%p] % p;
        n /= p;
    }
    return res;
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