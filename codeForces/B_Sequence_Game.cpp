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

    vi a(n);
    for(auto &x: a){
        cin>>x;
    }

    vi res = {a[0]};
    forr(i,1,n){
        if(a[i-1]<=a[i]){
            res.push_back(a[i]);
        }
        else{
            if(a[i]>=res.back()){
                int aux = min(a[i],res.back());
                res.pb(aux-1);
                res.pb(a[i]);
            }
            else{
                res.pb(a[i]);
                res.pb(a[i]);
            }
        }
    }

    debln(sz(res));
    for(auto x: res){
        deb(x);
    }
    debln("");
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    int t=1;
    cin>>t;
    while(t--){
        sol();
    }

    return 0;
}