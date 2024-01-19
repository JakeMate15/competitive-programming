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
    int a, b, c, d, h;
    cin >> a >> b >> c >> d >> h;

    int sum = a + b + c + d;
    int res1 = 60 * 60 * (sum < 24 ? 24 - sum : 0);

    int res2 = (1.0 * h / 24.0) * res1;

    cout << res1 << " " << res2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}