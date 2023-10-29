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
    //cerr << "======================\n";
    int n, s;
    cin >> n >> s;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    int mx = INT_MAX;
    for(int i = 1; i <= n; i++) {

        int l = i, r = n, res = -1;
        while(l <= r) {
            int m = (l + r) / 2;

            if(a[m] - a[i - 1] <= s) {
                res = m;
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }

        //cerr << res << " " << a[res] - a[i - 1] << " " << s << "\n";
        if(res == -1 || a[res] - a[i - 1] != s) 
            continue;
        mx = min(mx, n - (res - i + 1));
    }

    cout << (mx == INT_MAX ? -1 : mx) << "\n";
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