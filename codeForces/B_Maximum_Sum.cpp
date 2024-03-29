#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multi_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

ll binPow(ll x, ll n, ll m) {
    assert(n >= 0);
    x %= m;
    ll res = 1;
    
    while (n > 0) {
        if (n & 1)
            res = res * x % m;
        x = x * x % m;
        n >>= 1;
    }
    
    return res;
}

void sol() {
    int n, k;
    cin >> n >> k;
 
    ll mxS = 0, sum = 0, ss = 0, x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        sum = max(x, sum + x);
        mxS = max(mxS, sum);
        ss += x;
    }

    ll sk = (mxS % mod * binPow(2, k, mod)) % mod;
    ll res = (ss + sk) % mod;
    res -= mxS;
    res += mod;
    res %= mod;
    res += mod;
    res %= mod;
    
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}