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
    string s1,s2;cin>>s1>>s2;

    if(s1==s2){
        debug(0);
        return;
    }
    string aux = s2;
    reverse(all(aux));
    if( aux == s1 ){
        debug(2);
        return;
    }

    int op1,op2;
    forn(i,sz(s1)){
        if( s1[i]!=s2[i] )  op1++;
    }

    forn(i,sz(s1)){
        if( s1[i]!=aux[i] )  op2++;
    }

    debug( min( 2*op2, 4 ) );

}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}