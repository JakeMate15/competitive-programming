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
    ll n,m,d;
    cin>>n>>m>>d;

    vector<ll> a(n+1);
    fore(i,1,n){
        cin>>a[i];
    }

    ll sum = 0,res=0;
    multiset<ll> ms;
    fore(i,1,n){
        if(a[i] > 0){
            sum+=a[i];
            ll curr = sum-d*(i);
            res = max(res,curr);
            
            ms.insert(a[i]);
            if(sz(ms)>=m){
                sum-=*(ms.begin());
                ms.erase(ms.begin());
            }
        }
    }
    debln(res);

}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t=1;
    cin>>t;
    while(t--){
        sol();
    }

    return 0;
}