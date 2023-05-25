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
    //cout << "hola" << endl;
    int x,k;cin>>x>>k;
    if(k>x){
        debug(1);
        debug(x);
        return;
    }
    //cout << x << " " << k << endl;

    vector<int> res;
    int meta = x;
    int aux = meta;
    while(meta!=0){
        if(aux%k!=0){
            res.push_back(aux);
            meta-=aux;
            aux = meta;
        }   
        else{
            aux--;
        }
    }

    debug(res.size());
    for(int x: res) cout << x << " ";
    debug("");
}

int main(){
    int t=1;
    cin>>t;
    while(t--)  sol();
}