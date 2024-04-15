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
const ll inf = 1e18;

void sol() {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n + 1), b(n + 1), pref(n + 2, inf);
    pref[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        pref[i] = b[i] + pref[i - 1];
    }

    vector<ll> dp(n + 2, inf);
    ll mn = inf;
    for (int i = n; i >= 1; i--) {
        dp[i] = min(a[i] + pref[n] - pref[i], mn + a[i]);
        mn = min(dp[i], mn + b[i]);
    }

    cout << *min_element(dp.begin() + 1, dp.begin() + 1 + k) << "\n";
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