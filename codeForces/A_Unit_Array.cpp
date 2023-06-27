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
    int a[n];
    int pos = 0, neg = 0;
    
    forn(i,n){
        cin>>a[i]; 
        if(a[i] == 1)   pos++;
        else            neg++;
    }

    int res = 0;
    if(neg%2==1){
        res++;
        pos++;
        neg--;
    }

    while(neg>pos){
        pos+=2;
        neg-=2;
        res+=2;
    }

    debug(res);
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}