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
    ll s, res = 0;
    int n;
    cin >> n >> s;

    vector<int> l(n + 5), r(n + 5), c(n + 5);
    vector<ll> dp(n + 5);
    multiset<ll> ms;
    vector<pair<int, int>> v;

    for(int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i] >> c[i];
        v.emplace_back(l[i], -i);
        v.emplace_back(r[i], i);
    }

    sort(all(v));
    

    for(auto [a, b] : v){
        if(b < 0){
            dp[-b] = res + s * (r[-b] - l[-b] + 1) - c[-b];
            if(!ms.empty())
                dp[-b] = max(dp[-b], (*ms.rbegin()) + s * r[-b] - c[-b]);
            ms.insert(dp[-b] - s * r[-b]);
        }
        else{
            res = max(res, dp[b]);
            ms.erase(ms.lower_bound(dp[b] - s * r[b]));
        }
    }
    
    cout << res << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t=1;
    //cin>>t;

    while(t--){
        sol();
    }

    return 0;
}
