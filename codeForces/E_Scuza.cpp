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

void sol(){
    int n, q;
    cin >> n >> q;

    vector<ll> a(n), pref(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i] = a[i] + (i ? pref[i - 1] : 0);
        a[i] = i ?  max(a[i], a[i - 1]) : a[i];
    }

    while(q--) {
        int h;
        cin >> h;

        auto it = prev(lower_bound(all(a), h + 1));
        int pos = it - a.begin();
        if(it == a.end() || pos == -1) {
            cout << 0 << " ";
        }
        else {
            cout << pref[pos] << " ";
        }
    }
    nl;
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