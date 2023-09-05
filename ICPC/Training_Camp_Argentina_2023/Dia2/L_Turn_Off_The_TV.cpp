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
#define sz(a)       (int)a.size()

void sol(){
        int n;
        cin>>n;

        map<int,pair<vi,vi>> m;
        bool ok[200200];

        forn(i,n){
                int l,r;
                cin>>l>>r;

                m[l].first.push_back(i);
                m[r].second.push_back(i);
                m[r-1];
                m[l-1];

                ok[i] = true;
        }

        set<int> aux;
        for(auto x: m){

                for(int j: x.second.first){
                        aux.insert(j);
                }

                if(sz(aux)==1){
                        ok[*aux.begin()] = false;
                }


                for(int j: x.second.second){
                        aux.erase( aux.find(j) );
                }
        }

        forn(i,n){
                if(ok[i]){
                        debug(i+1);
                        return;
                }
        }


        debug(-1);
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}