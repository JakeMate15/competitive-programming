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

const int MX = 1e5+10;

void sol(){
        int n,m;
        cin>>n>>m;

        int a[MX],b[MX];
        set<int> aux;

        fore(i,1,n){
                cin>>a[i];
                aux.insert(a[i]);
        }
        
        fore(i,1,m){
                cin>>b[i];
                aux.insert(b[i]);
        }
        
        sort(a+1,a+n+1);
        sort(b+1,b+m+1);

        vector<lli> aa(MX),bb(MX);
        fore(i,1,n)
                aa[i] = aa[i-1] + a[i];
        
        fore(i,1,m)
                bb[i] = bb[i-1] + b[i];


        lli res = LONG_LONG_MAX;

        for(int x: aux){
                int up = upper_bound(a+1, a+n+1, x) - a - 1;
                int lw = lower_bound(b+1, b+m+1, x) - b;

                lli aux2 = x * lli(up-(m-lw+1)) + (bb[m] - bb[lw-1] - aa[up]) ;
                //debug(aux2);
                res = min(res,aux2);
        }

        debug(res);
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}