#include<bits/stdc++.h>
using namespace std;
 
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
 
typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

void sol(){
    int l, r, x;
    cin >> l >> r >> x;
    
    int ans = r / x + r % x;
    int m = r / x * x - 1;
    if(m >= l)
        ans = max(ans, m / x + m % x);
    cout << ans << "\n";             
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t=1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}