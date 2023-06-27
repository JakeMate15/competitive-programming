#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(int (i)=0; i<n; i++)
#define forr(i,a,n) for(ll i=(a); i<n; i++)
#define fore(i,a,n) for(ll i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"
#define sz(a)       (int)a.size()

const int N = 2e5+10;
ll dp[N][5][2];
bool calculado[N][5][2];
vector<int> valores = {1,10,100,1000,10000};
string numero;

ll mem(int pos, int valorMax, int cambios){
    if(pos<0)   return 0;
    ll &a = dp[pos][valorMax][cambios];
    if(calculado[pos][valorMax][cambios])   return a;
    calculado[pos][valorMax][cambios] = true;
    a = LONG_LONG_MIN;

    //No hago cambios de numeros
    int digAct = numero[pos]-'A';
    a = mem(pos-1, max(valorMax,digAct), cambios) + (digAct<valorMax? -valores[digAct] : valores[digAct]); 

    if(!cambios){
        forn(i,6){
            a = max(a, mem(pos-1,max(valorMax,i),1) + (i<valorMax? -valores[i]: valores[i]) );
        }
    }

    return a;
}

void sol(){
    cin>>numero;
    forn(i,sz(numero)){
        forn(j,5)
            forn(k,2)
                calculado[i][j][k] = false;
    }
    debug(mem(sz(numero)-1,0,0));
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}