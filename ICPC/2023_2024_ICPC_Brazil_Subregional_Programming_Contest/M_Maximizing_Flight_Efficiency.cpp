#include<bits/stdc++.h>
using namespace std;

#define forn(i,n)       for(int i=0; i<n; i++)
#define forr(i,a,n)     for(int i=a; i<n; i++)
#define fore(i,a,n)     for(int i=a; i<=n; i++)
#define fornd(i,n)      for(int i=n; i>=0; i--)
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define pb              push_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

void sol(){
    int n;
    cin>>n;
    pair<int,int> d[n][n],a[n][n];

    forn(i,n){
        forn(j,n){
            cin>>d[i][j].first;
            d[i][j].second = 1;
            a[i][j] = d[i][j];
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if( d[i][j].first >= d[i][k].first + d[k][j].first ){
                    d[i][j].second = max(d[i][j].second,d[i][k].second + d[k][j].second);
                    d[i][j].first = min(d[i][j].first, d[i][k].first + d[k][j].first); 
                }
            }
        }
    }

    map<int,int> res;
    forn(i,n){
        forn(j,n){
            if(a[i][j].first>d[i][j].first){
                debln(-1);
                return;
            }
            res[d[i][j].second]++;
        }
    }

    if(sz(res)<=2){
        debln(0);
    }
    else{
        auto it = res.begin();
        it++;it++;
        int ans = 0;
        for(it; it!=res.end(); it++){
            ans+=(*it).second;
        }
        debln(ans/2);
    }

}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int t=1;
    //cin>>t;
    while(t--){
        sol();
    }

    return 0;
}