#include<bits/stdc++.h>
using namespace std;
 
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl()            cout << "\n"
typedef long long ll;
 
const int mx = 1e6+5;
const int mod = 1e9+7;
 
vector<int> coins;
int dp[mx][105];
 
int sol(int meta, int moneda) {
    int &mem = dp[meta][moneda];
    if(meta == 0)   return mem = 1;
    if(meta < 0)    return mem = 0;
 
    if(mem != 0)    return mem;
 
    for(auto c: coins) {
        if(meta - c < 0 || c > moneda) continue;
 
        mem += (sol(meta - c, c)) % mod;
    }
 
    return (mem)%mod;
}
 
void sol(){
    int n, x;
    cin >> n >> x;
 
    coins.resize(n);
    for(auto &y: coins) {
        cin >> y;
    }
 
    debln(sol(x, mx-5));
    
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