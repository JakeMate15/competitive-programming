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
    int n,x;cin>>n>>x;
    vi a(n),b(n),c(n);

    for(auto &y: a) cin>>y;
    for(auto &y: b) cin>>y;
    for(auto &y: c) cin>>y;

    int aux=0;

    for(auto y: a){
        //cout << y << " ";
        if((y|x)!= x)  break;
        aux|=y;
    }

    for(auto y: b){
        if((y|x )!= x)    break;
        aux|=y;
    }

    for(auto y: c){
        if((y|x )!= x)    break;
        aux|=y;
    }

    if(aux == x)    debug("Yes");
    else            debug("No");
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}