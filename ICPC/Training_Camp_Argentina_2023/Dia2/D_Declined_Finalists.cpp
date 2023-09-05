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
        int n;
        cin>>n;
        vi a(n);

        lli res = 0;
        for(auto &x: a){
                cin>>x;
        }

        sort(all(a));

        auto it = upper_bound(all(a),25);
        
        if(it==a.begin()){
                //debug("hola");
                res+= ((*it-25));
                //debug(res);

                forr(i,1,n){
                        res+=(a[i]-a[i-1]);
                }
        }
        if(it==a.end()){
                res =0;
        }
        else{
                
                int pos = it-a.begin();
                res = a[pos]-25;
                forr(i,pos+1,n){
                        res+=(a[i]-a[i-1]);
                }
        }

        debug(res);

}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}