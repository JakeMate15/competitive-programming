#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(int (i)=0; i<n; i++)
#define forr(i,a,n) for(int i=(a); i<n; i++)
#define fore(i,a,n) for(int i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"

const int mx = 3000+5;
ll votos[mx], copia[mx]; 

struct ura{
    ll partido, precio;
}v[mx];

bool cmp(const ura &a, const ura &b){ 
        return a.precio < b.precio; 
}
bool vis[mx];

void sol(){
        ll n,m;
        cin>>n>>m;

        forn(i,n){
                cin>>v[i].partido>>v[i].precio;
                votos[v[i].partido]++;
        }

        sort(v,v+n,cmp);
        ll res=LLONG_MAX,cur,votosAlc;

        fore(i,1,n){ //tomar al menos i votos
                cur = 0;
                votosAlc = votos[1];

                fore(j,1,m)
                        copia[j] = votos[j];
                forn(j,n)
                        vis[j] = false;

                /*
                fore(j,1,m){
                        cout << copia[i] << " " << vis[j] << endl;
                }
                */

                // como prioridad está tomar de aquellos que tienen mas que i, ya que al final votes[partido] < i,
                forn(j,n){      
                        if( v[j].partido !=1 && copia[ v[j].partido ] >= i ){
                                copia[v[j].partido]--;
                                vis[j]=true;
                                cur+=v[j].precio;
                                votosAlc++;
                        }
                }

                //Revisar lo que pasa si no hay suficientes votos
                if(votosAlc < i){
                        forn(j,n){
                                if(!vis[j] && v[j].partido != 1 ){
                                        votosAlc++;
                                        cur+=v[j].precio;
                                        if(votosAlc == i) 
                                                break;
                                }
                        }
                }
                res = min(res, cur);
        }
        debug( res );
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}