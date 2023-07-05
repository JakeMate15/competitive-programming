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
    int n,m,aux=0;cin>>n>>m;
    vector<int>a(n);

    for(auto &x: a){
        cin>>x;
        if(x==0)    aux++;
    }

    if(n==m){
        debug("Richman");
        return;
    }

    if(aux>m){
        debug("Impossible");
        return;
    }

    lli sum = 0;
    m-= aux;
    int it=0;
    for(auto x: a){
        if(m<=0)        break;
        else if(x==0)   continue;
        sum+=x;
        m--;
        it++;
    }
    
    debug("hola");
    debug(m);
    debug(it);
    debug(sum);
    debug("adios");
    
    

    int minimo = INT_MAX;
    forr(i,it,n){
        if(a[i]>0)
            minimo = min(minimo,a[i]);
    }

    debug(sum+minimo-1);
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}

/*
hola
0
2
3
adios
6
hola
0
0
0
adios
96
Richman
Impossible
*/