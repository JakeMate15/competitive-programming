#include<bits/stdc++.h>
using namespace std;
 
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";
 
typedef long long ll;
typedef long double ld;
 
const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

void sol(){
    int a, b;
    cin >> a >> b;

    
    if(a == b) {
        cout << "infinity\n";
        return;
    }
    if(a < b) {
        cout << "0\n";
        return;
    }

    int res = 0, m = a - b;
    for (int x = 1; x * x <= m; x++) {
        if (m % x == 0) {
            if (x > b) {
                res++;
            }
            if (x * x != m && m / x > b) {
                res++;
            }
        }
    }


    cout << res << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t=1;
    // cin>>t;

    while(t--){
        sol();
    }

    return 0;
}