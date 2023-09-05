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
#define sz(a)       (int)a.size()

void sol(){
        lli g[26][26];
        forn(i,26){
                forn(j,26){
                        cin>>g[i][j];
                }
                g[i][i] = 0;
        }
        
        forn(i,26){
                forn(j,26){
                        forn(k,26){
                                g[j][k] = min(g[j][k],g[j][i]+g[i][k]);
                        }
              }  
        }

        string s;
        cin>>s;
        lli ans = 0;

        forn(i,sz(s)/2){
                lli aux = LONG_LONG_MAX;
                lli a = s[i] - 'a';
                lli b = s[sz(s)-i-1]-'a';
                forn(j,26){
                        if(aux>g[a][j]+g[b][j])
                                aux = g[a][j] + g[b][j];
                }
                ans+=aux;
        }

        debug(ans);
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}