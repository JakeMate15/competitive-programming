#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

gp_hash_table<ll, int,custom_hash> m1;

void sol(){
    int n;
    ll x;
    cin>>n>>x;
 
    vi a(n);
    forn(i,n){
        cin>>a[i];
    }
 
    forr(msk,0,1<<(n/2)){
        ll sum = 0;
        forn(i,20){
            if( (1<<i)&msk ){
                sum+=a[i];
            }
        }
        m1[sum]++;
    }
 
    ll res = 0;
    forr(msk,0,1<<((n+1)/2)){
        ll sum = 0;
        forn(i,20){
            if((1<<i)&msk){
                sum+=a[i+n/2];
            }
        }

        if(m1.find(x-sum)!=m1.end())
            res += ( m1[x-sum] );
    }
 
    debln(res);
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