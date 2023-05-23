//https://codeforces.com/contest/1833/problem/C
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(ll (i)=0; i<n; i++)
#define forr(i,a,n) for(ll i=(a); i<n; i++)
#define fore(i,a,n) for(ll i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"

void sol(){
    int n;cin>>n;
    int a[n];
    forn(i,n)   cin>>a[i];

    sort(a,a+n);
    int prim = a[0];

    int paridad = prim%2;
    if(paridad==1){
        debug("YES");
        return;
    }
    else{
        forr(i,1,n){
            if(a[i]%2!=paridad){
                debug("NO");
                return;
            }
        }
    }
    debug("YES");
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}