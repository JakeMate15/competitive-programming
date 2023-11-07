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
    cerr << "====================\n";
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    int mn = INT_MAX / 2, mx = INT_MAX / 2;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] <= k && abs(a[i] - k) < abs(mn - k)) 
            mn = a[i];
        if(a[i] > k) {
            int veces = ceil((1.0 * a[i]) / k);
            if(veces * k - a[i] <= mx) {
                mx = a[i];
            } 
        }
            
    }

    cerr << mn << " " << mx << "\n";
    int me = INT_MAX, ma = INT_MAX;
    if(mn != INT_MAX / 2) {
        me = k - mn;
    }
    if(mx != INT_MAX / 2) {
        int veces = ceil(1.0 * mx / k);
        ma = veces * k - mx;
        //cerr << veces << "\n";
        //cerr << ma << "\n";
    }

    //cerr << ma << " " << me << "\n\n";
    cout << min(ma, me) << "\n";
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