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

int main(){IO
    int t=1;
    cin>>t;

    set<ll> posibles;

    fore(i,2,1000){
        ll pot = 1+i;
        ll aux = i*i;

        while(aux<=1e6){
            pot+=aux;
            posibles.insert(pot);
            aux*=i;
        }
    }

    while(t--){
        int n;
        cin>>n;
        if(n<=6){
            debug("NO");
        }
        else{
            if(posibles.count(n))   debug("YES");
        else                    debug("NO");    
        }
    }
}