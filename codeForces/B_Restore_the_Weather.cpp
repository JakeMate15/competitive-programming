#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> pii;
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
        int n,m;cin>>n>>m;
        vector<pii> a,b;

        forn(i,n){
                int lec;cin>>lec;
                a.emplace_back(lec,i);
        }

        forn(i,n){
                int lec;cin>>lec;
                b.emplace_back(lec,i);
        }

        sort(all(a));
        sort(all(b));

        map<int,int> res;
        forn(i,a.size()){
                res[a[i].second] = b[i].first;
        }

        for(auto x: res){
                cout << x.second << " ";
        }

        debug("");

}

int main(){IO
    int t=1;    
    cin>>t;
    while(t--)  sol();
}