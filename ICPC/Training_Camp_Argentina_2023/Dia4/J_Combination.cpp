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

bool cmp(pair<int,int> a, pair<int,int> b){
        if(a.second==b.second){
                return a.first>b.first;
        }
        return  a.second>b.second;
}

void sol(){
        int n;
        cin>>n;

        vector<pair<int,int>> cartas(n);
        forn(i,n){
                cin>>cartas[i].first;
                cin>>cartas[i].second;
        }

        sort(cartas.begin(),cartas.end(),cmp);
        int t=1;
        int res=0;
        int i=0;
        while(t>0 && i<n ){
                res+=cartas[i].first;
                t+=cartas[i].second;
                t--;
                i++;
        }
        debug(res);

}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}