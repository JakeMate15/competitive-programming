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

const int mx = 100100;
int a[mx];

void sol(){
        int n,k;
        cin>>n>>k;
        set<int> s;

        forn(i,n){
                cin>>a[i];
                s.insert(a[i]);
        }

        int mex = -1;
        fore(i,0,n+1){
                if(s.find(i) == s.end()){
                        mex = i;
                        break;
                }
        }

        int maxv = *s.rbegin();
        if(k==0){
                debug(n);
                return;
        }

        if(mex>maxv){
                debug(n+k);
                return;
        }
        else{
                int v = (mex + maxv + 1) / 2;
                if (s.find(v) == s.end())
                        n++;
                debug(n);
        }

}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}
