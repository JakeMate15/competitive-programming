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
#define sz(a)       (int)a.size()

void sol(){
    int n;cin>>n;

    ll res = 0;
    forn(i,n){
        int a,b;cin>>a>>b;
        if(a-b>0)   res++;
    }

    debug(res);
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}