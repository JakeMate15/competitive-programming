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

const int mx = 1e7;
int a[mx],cubeta[mx];

void sol(){
        int n,k;
        cin>>n>>k;

        forn(i,n){
                cin>>a[i];
                cubeta[a[i]]++;
        }

        forr(i,1,mx){
                cubeta[i]+=cubeta[i-1];
        }

        int res = n;
        forn(i,n){
                if(cubeta[a[i]+k]-cubeta[a[i]]>0){
                        res--;
                }
        }

        debug(res);
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}