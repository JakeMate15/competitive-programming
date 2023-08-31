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
    string s = "vika";
    int aux = 0;

    vector<string> a(n);
    for(auto &x: a){
        cin>>x;
    }

        forn(i,m){
                forn(j,n){
                        if(a[j][i] == s[aux]){
                                aux++;
                                break;
                        }
                }
        }

        //debug(aux);
    cout << (aux==4?"YES":"NO") << endl;
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}