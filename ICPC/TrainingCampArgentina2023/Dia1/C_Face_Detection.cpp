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
        int n,m;
        cin>>n>>m;

        vector<string> a(n);
        forn(i,n)       
                cin>>a[i];

        string aux = "face";
        sort(all(aux));
        string res = "";
        int ans = 0;

        forn(i,n-2+1){
                
                forn(j,m-2+1){
                        if(i<n-1 && j<m-1){
                                res = "";
                                //cout << i << " " << j << endl;
                                res+=a[i][j];
                                res+=a[i][j+1];
                                res+=a[i+1][j];
                                res+=a[i+1][j+1];

                                sort(all(res));
                                if(res==aux)    
                                        ans++;
                        }
                                
                }
                

                //cout << res << "\n";
        }

        

        debug(ans);
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}