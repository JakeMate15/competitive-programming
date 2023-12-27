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
    ll n, p, l, t;
    cin >> n >> p >> l >> t;
    ll tareas = (n - 1) / 7 + 1;

    ll lo = -1, hi = n + 1;
    while(lo + 1 < hi) {
        ll mid = (lo + hi) / 2;

        ll dT = n - mid;
        ll pts = dT * l + min(2 * dT, tareas) * t;

        if(pts >= p)    lo = mid;
        else            hi = mid;
    }

    cout << lo << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}