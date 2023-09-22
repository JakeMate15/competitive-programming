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
int x;

void sol(){
    int n,m;
    cin>>n>>m;

    vi a(32,0);
    forn(i,n){
        cin>>x;
        forn(j,32){
            if( (1<<j) & x ) {
                a[j]++;
            }
        }
    }

    int msk = 0;
    forn(i,m) {
        cin>>x;
        msk|=x;
    }

    int mn = 0, mx = 0;
    forn(i,32) {
        if(a[i]&1) {
            mx|=(1<<i);
            
            mn|=(1<<i);
            if(!(n&1) && (msk&(1<<i))){
                mn &= (~(1<<i));
            }
        }
        else{
            if( (n&1) && ((1<<i) & msk) ) {
                mx|=(1<<i);
            }
        }
    }
    
    deb(mn);debln(mx);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int t=1;
    cin>>t;
    while(t--){
        sol();
    }

    return 0;
}