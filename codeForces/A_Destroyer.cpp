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
    map<int,int> numeros;

    forn(i,n){
        int aux;cin>>aux;

        if(numeros.count(aux))  numeros[aux]++;
        else                    numeros[aux]=1;
    }

    int tam = numeros.size();
    int i = 0;
    vector<int> aux;

    for(auto [llave,valor]: numeros){
        if(llave == i){
            aux.push_back(valor);
        }
        else{
            debug("NO");
            return;
        }

        i++;
    }

    forr(i,1,tam){
        if(aux[i-1] >= aux[i]){}
        else{
            debug("NO");
            return;
        }
    }

    debug("YES");
    
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}