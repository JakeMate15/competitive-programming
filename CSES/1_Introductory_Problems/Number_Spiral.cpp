#include<bits/stdc++.h>
using namespace std;

#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(int (i)=0; i<n; i++)
#define forr(i,a,n) for(int i=(a); i<n; i++)
#define fore(i,a,n) for(int i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"
#define sz(a)       (int)a.size()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

void sol(){
    int t;cin>>t;

    ll x,y,res;
    while(t--){
        cin>>x>>y;

        if(x<y){
            if(y%2==1)  res = y*y-x+1;
            else        res = (y - 1) * (y - 1) + 1 + x - 1;
        }
        else{
            if(x%2==1)  res = (x - 1) * (x - 1) + 1 + y - 1;
            else        res = x*x - y + 1;
        }

        debug(res);
    }
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}