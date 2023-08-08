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
        int n;string s;
        cin>>n>>s;

        int amigos;
        cin>>amigos;

        int rep[n+1][27];
        memset(rep,0,sizeof(rep));

        forn(i,n){
                rep[i][s[i]-'a'] = 1;
        }

        forr(i,1,n+1){
                forn(j,26){
                        rep[i][j]+=rep[i-1][j];
                }
        }

        /*        
        forn(i,n+1){
                forn(j,26){
                        cout << rep[i][j] << " ";
                }
                debug("");
        }
        */


        while(amigos--){
                string nombre;
                cin>>nombre;
                map<char,int> aux;

                for(char c: nombre){
                        if( aux.count(c) )      aux[c]++;
                        else                    aux[c]=1;
                }

                int l,r,m;
                l=0,r=n-1;
                
                while(l<=r){
                        m = (l+r)/2;

                        bool ok = true;
                        for(auto x: aux){
                                if( rep[m][x.first-'a'] < x.second ){
                                        ok = false;
                                        break;
                                }
                        }

                        if(ok)  r = m-1;
                        else    l = m+1;
                }

                debug(++l);
                


        }

        //No olvidar poner el io
}
       

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}