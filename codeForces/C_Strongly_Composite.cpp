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

set<int> factores;

void sol(){
    int n;cin>>n;
    factores.clear();

    int res = 0;
    int f;
    forn(i,n){
        cin>>f;
        for(int x=2;x*x<=f; x++){
            while(f%x==0){
                if(factores.count(x)){
                    res++;
                    factores.erase(x);
                }
                else{
                    factores.insert(x);
                }
                f/=x;
            }
        }
        if(f>1){
            if(factores.count(f)){
                res++;
                factores.erase(f);
            }
            else factores.insert(f);
        }
    }
    //cout<< "el res antes es " << res << endl;
    //for(int x: factores)    cout << x << " ";
    //debug("");
    res+=(factores.size()/3);
    debug(res);
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}

//3 7 11 13 17 31