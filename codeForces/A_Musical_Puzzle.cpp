//https://codeforces.com/contest/1833/problem/A
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
    int n;cin>>n;
    string s;cin>>s;
    set<string> res;
    forn(i,n-1){
        string aux = "";
        aux+=s[i];
        aux+=s[i+1];
        res.insert(aux);
    }
    debug(res.size());
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}