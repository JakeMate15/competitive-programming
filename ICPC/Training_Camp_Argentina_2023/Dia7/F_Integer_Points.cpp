#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
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
        ll n,m,aux,par,impar;
        cin>>n;
        par=impar=0;

        forn(i,n){
                cin>>aux;
                if(aux&1)       impar++;
                else            par++;
        }

        cin>>m;
        ll res = 0;
        forn(i,m){
                cin>>aux;
                if(aux&1)       res+=impar;
                else            res+=par;
        }

        debug(res);
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}

