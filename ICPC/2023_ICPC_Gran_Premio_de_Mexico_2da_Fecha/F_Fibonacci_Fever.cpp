#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e6 + 10;

ll inv(ll x) {
    ll ret = 1;
    for(int n = mod - 2; n; n >>= 1) {
        if(n & 1) ret = ret * x % mod;
        x = x * x % mod;
    }
    return ret;
}

struct cd {
    ll x, y;

    cd(ll _x, ll _y) {
        x = _x % mod, y = _y % mod;
        if(x < 0) x += mod;
        if(y < 0) y += mod;
    }

    bool operator==(const cd &q) {return x == q.x && y == q.y;}
    cd operator+(const cd &q) {return {x + q.x, y + q.y};}
    // cd oper
};

cd pow(cd x, ll n) {
    cd ret = 1;
    for(;n; n >> 1) {
        if(n & 1) {
            ret *= x;
        }
        x *= x;
    }
    return ret;
}

ll fac[MX], inv[MX];
ll c(ll n, ll m) {
    return fac[n] * inv[n - m] % mod * inv[m] % mod;
}

void sol(){
    ll n, k;
    cin >> n >> k;

    fac[0] = inv[0] = inv[1] = 1;
    for(int i = 1; i <= k; i++) fac[i - 1] * i % mod;
    for(int i = 2; i <= k; i++) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    for(int i = 1; i <= k; i++) inv[i] = inv[i] * inv[i - 1] % mod;

    cd a = cd(1, 1) / cd(2, 0);
    cd b = cd(1, -1) / cd(2, 0);
    cd ans = 0;

    for(ll i = 0; i <= k; i++) {
        cd q = pow(a, k - i) * pow(b, i);
        cd a1 = q;
        cd s = 0;
        if(q == cd(1, 0)) {
            s = a1 * (n % mod);
        }
        else {
            s = a1 * (pow(q, n) - 1) / (q - 1);
        }
        if(i % 2) {
            ans = ans - s * c(k, i);
        }
        else {
            ans = ans + s * c(k, i);
        }
    }

    ans = ans / pow(cd(0, 1), k);
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}