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
        lli res = 0;
        string s;
        cin >> s;
        for (char &c : s) 
                c -= '0';

        forn(i,sz(s)) {
                if ( !(s[i] % 4) ) 
                        res++;
                if (i && (10 * s[i-1] + s[i]) % 4 == 0) 
                        res += i;
        }

        debug(res);
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}