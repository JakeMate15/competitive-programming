//https://codeforces.com/problemset/problem/1832/C
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
    vector<int>a(n);

    for(int &x: a)  cin>>x;
    
    auto it = unique(all(a));
    int res,fin;
    res = fin = it-a.begin();

    for(int i=0; i<fin-2; i++){
        if( (a[i]>a[i+1] && a[i+1]>a[i+2]) || (a[i]<a[i+1] && a[i+1]<a[i+2]) )  res--;
    }
    debug(res);
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}