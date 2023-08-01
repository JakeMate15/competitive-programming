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
#define YES         cout << "Yes\n"
#define NO          cout << "No\n"
#define debug(a)    cout << a << "\n"

const int MX = 1e5+10;
int ok[2*MX], l[MX], r[MX], m[MX],res;
vi g[MX];

void dfs(int u){
        res++;
        l[u] = res;

        for(auto v: g[u]){
                if(ok[v] == 0){
                       ok[v] = 1;
                       dfs(v);
                       ok[v] = 0; 
                }
        }
        r[u] = res;
}

void sol(){
        int n,q,su;
        cin>>n>>q;

        forn(i,n){
                int lec;
                cin>>lec;
                if(lec!=-1){
                        g[lec].push_back(i);
                        m[i]++;
                }
        }

        forn(i,n){
                if(m[i] == 0){
                        ok[i] = 1;
                        dfs(i);
                }
        }

        fore(i,1,q){
                int x,y;
                cin>>x>>y;

                if(l[x]>=l[y] && r[x]<=r[y])    YES;
                else                            NO;
        }
        
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}