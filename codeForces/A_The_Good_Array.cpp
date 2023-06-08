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

void sol(){
    int n,k;cin>>n>>k;
    int res = 0;

    int aux;
    int aux2;
    fore(i,1,n){
        aux2 = ceil(1.0*i/k);
        int comparten = i*2-n;
        if(comparten>0){
            aux = (aux2-comparten)*2+comparten;
            res = max(res,aux);
        }
        else{
            aux = aux2*2;
            res = max(res,aux2*2);
        }

        cout << i << " " << aux2 << " " << comparten << " " << aux << "\n";
    }

    //debug("\n");
    debug(res);
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}