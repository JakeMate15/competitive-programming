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
        int n,m;
        cin>>n>>m;

        if(n>m || m%n){
                debug(-1);
                return;
        }

        int aux = m/n;

        int aux1 = 0, aux2 = 0;
        while(aux%3==0){
                aux/=3;
                aux2++;
        }

        while(aux%2==0){
                aux/=2;
                aux1++;
        }

        if(aux!=1){
                debug(-1);
        }
        else{
                debug(aux1+aux2);
        }

}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}
