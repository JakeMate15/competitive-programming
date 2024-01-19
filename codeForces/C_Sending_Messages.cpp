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
    ll n, f, a, b, res = 1;
    cin >> n >> f >> a >> b;

    ll ant = 0, x = 0;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        f -= min((x - ant) * a, b);
        res &= (f <= 0 ? 0 : 1);
        ant = x;
    }

    cout << (res ? "YES" : "NO") << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}