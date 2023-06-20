//https://omegaup.com/arena/problem/nbf/
#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef long double ld;
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
    lli n;cin>>n;
    lli fib[46];
    fib[0] = fib[1] = 1;

    fore(i,2,44)    fib[i] = fib[i-1] + fib[i-2];
    vector<int> res;
    
    int fin = lower_bound( fib, fib+46, n ) - fib;

    for(int i=fin; i>=0; i--){
        if(fib[i]<=n){
            n-=fib[i];
            res.push_back(i);
        }
        else if(n==0)   break;
    }

    debug(res.size());
    for(int x: res) cout << x << " ";
    debug("");
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}