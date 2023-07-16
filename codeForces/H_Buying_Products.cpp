#include<bits/stdc++.h>
using namespace std;

#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(int (i)=0; i<n; i++)
#define forr(i,a,n) for(int i=(a); i<n; i++)
#define fore(i,a,n) for(int i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"
#define sz(a)       (int)a.size()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

void sol(){
    int n,k;cin>>n>>k;
    
    vector<multiset<int>> a(n);
    forn(i,n){
        forn(j,3){
            int lec;cin>>lec;
            a[i].insert(lec);
        }
    }

    multiset<int> res;
    forn(i,n){
        auto it = a[i].begin();
        res.insert(*it);
        it++;
        res.insert(*it);
    }

    ll ans = 0;
    for(auto x: res){
        if(k<=0)    break;
        ans+=x;
        k--;
    }

    debug(ans);
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}