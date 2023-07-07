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
    vector<string> t(3);
    for(auto &x: t) cin>>x;

    if( t[0][0] == t[0][1] && t[0][0] == t[0][2] && t[0][0] != '.'){
        debug(t[0][0]);
        return;
    }

    if(t[1][0] == t[1][1]  && t[1][0] == t[1][2] && t[1][0] != '.'){
        debug(t[1][0]);
        return;
    }

    if(t[2][0] == t[2][1]   && t[2][0] == t[2][2] && t[2][0] != '.'){
        debug(t[2][0]);
        return;
    }

    if( t[0][0] == t[1][0]  && t[0][0] == t[2][0] && t[0][0] != '.'){
        debug(t[0][0]);
        return;
    }

    if( t[0][1] == t[1][1]  && t[0][1] == t[2][1] && t[0][1] != '.'){
        debug(t[0][1]);
        return;
    }

    if( t[0][2] == t[1][2]  && t[0][2] == t[2][2] && t[0][2] != '.'){
        debug(t[0][2]);
        return;
    }

    if( t[0][0] == t[1][1]  && t[0][0] == t[2][2] && t[0][0] != '.'){
        debug(t[0][0]);
        return;
    }

    if( t[0][2] == t[1][1]  && t[0][2]  == t[2][0] && t[0][2] != '.'){
        debug(t[0][2]);
        return;
    }

    debug("DRAW");
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}