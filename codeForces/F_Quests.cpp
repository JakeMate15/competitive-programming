#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl              cout << "\n";
#define u_map           gp_hash_table
#define uid(a, b)       uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multi_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

bool ok(vector<ll> a, ll m, ll meta, ll dias) {
    ll curr = 0LL;

    // cerr << "M es " << m << " y dias son " << dias << "\n";

    for(int i = 0; i < min(m + 1, (ll)sz(a)); i++) {
        curr += a[i] * (dias / (m + 1) + (dias % (m + 1) > i));
        if(curr >= meta) {
            return true;
        }
            
    }
    // cerr << "\n\n";

    return false;
}

void sol(){
    // cerr << "==============\n";
    ll n, c, d;
    cin >> n >> c >> d;

    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(all(a), greater<int>());

    if(a[0] * d < c) {
        cout << "Impossible\n";
        return;
    }

    ll l = 0, r = 4 * 2e5;
    while(l <= r) {
        ll m = (l + r) / 2;
        bool o = ok(a, m, c, d);

        if(o)
            l = m + 1;
        else 
            r = m - 1;
    }

    l--;
    if(l > d) {
        cout << "Infinity\n";
    }
    else {
        cout << l << "\n";
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t=1;
    cin>>t;

    while(t--){
        sol();
    }

    return 0;
}