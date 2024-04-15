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

void sol() {
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n + 2), pref(n + 2), suf(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }

    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] + a[i];
    }

    ll l = (k + 1) / 2, r = k / 2;
    int i = 1;
    while (i <= n) {
        if (pref[i] > l)   break;
        i++;
    }

    int j = n;
    while (j >= 1) {
        if (suf[j] > r)    break;
        j--;
    }

    int res = (pref[n] <= k ? n : max(0LL, i + n - j - 1));
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