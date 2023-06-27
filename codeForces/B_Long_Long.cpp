//https://codeforces.com/contest/1843/problem/C
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
    lli n;cin>>n;
    vector<lli> a(n);
    lli sum =0;
    for(lli &x: a){
        cin>>x;
        sum+=abs(x);
    }

    int grupos = 0;
    bool aux = false;
    int auxC = 0;
    int ceros = 0,neg=0;

    for( int x: a ){
        if( x <= 0){
            aux = true;
            auxC++;
            if(x==0)        ceros++;
            else if(x<0)    neg++;
        }
        else{
            if(ceros < auxC)    grupos++;

            ceros = neg = auxC = 0;
            aux = false;
        }
    }

    if( aux ){
        if(ceros == auxC){}
        else                grupos++;
    }

    cout << sum << " " << grupos << "\n";
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}