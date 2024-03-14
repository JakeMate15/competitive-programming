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
const int inf = 1e18;

void sol() {
    int n;
    cin >> n;
    
    vector<int> D(n), L(n), R(n);
    for (int i = 0; i < n; i++) {
        cin >> D[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> L[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> R[i];
    }
    int a0, b0;
    cin >> a0 >> b0;
    
    set<pair<ll, ll>> s;
    s.emplace(a0, b0);
    
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += D[i];
        
        ll l = L[i] - sum;
        ll r = R[i] - sum;
        
        auto it = s.lower_bound({l, -inf});
        if (it != s.end() && it->second >= r) {
            ll y = it->second;
            ll x = -inf;
            while (it != s.end() && it->second >= r) {
                x = it->first;
                it = s.erase(it);
            }
            if (x > l) {
                s.emplace(x, r);
            }
            if (y >= r) {
                s.emplace(l, y);
            }
        }
    }
    
    ll ans = 0;
    for (auto [x, y] : s) {
        ans = max(ans, x + y + 2 * sum);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    //cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}