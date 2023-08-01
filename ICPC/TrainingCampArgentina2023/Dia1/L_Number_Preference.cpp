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
        lli n;
        cin>>n;

        map<lli, lli> res;
        set<lli> no;
        lli noG = 0;
        forn(i,n){
                lli op,amigos,lec;
                cin>>op>>amigos;

                if(op==1){
                        forn(i,amigos){
                                cin>>lec;

                                if(res.count(lec))      res[lec]++;
                                else                    res[lec]=1;
                        }
                }
                else{
                        noG++;
                        forn(i,amigos){
                                cin>>lec;
                                no.insert(lec);
                        }
                }
        }

        lli ans = 0;
        for(auto x: res){
                if(x.second == (n-noG) && !no.count(x.first))
                        ans++;
        }

        if(!res.size()) debug( ((lli)1e18-(lli)no.size()) );
        else            debug(ans);

        cerr << "hola" ;
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}