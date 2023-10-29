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
    int n, k;
    cin >> n >> k;

    map<int, int> mp;
    vector<int> a;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }

    for(auto [v,r]: mp) {
        if(r >= k)
            a.push_back(v);
    }

    if(!sz(a)) {
        cout << -1 << "\n";
        return;
    }

    a.push_back(-10);

    int l, r, cl, cr, ant;
    l = r = cl = cr = ant = a[0];

    for(int i = 1; i < sz(a); i++) {
        if(a[i] == ant + 1) {
            cr = a[i];
        }
        else{
            if(cr - cl >= r - l) {
                r = cr;
                l = cl;
            }

            cl = cr = a[i];
        }

        ant = a[i];
    }

    cout << l << " " << r << "\n";
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