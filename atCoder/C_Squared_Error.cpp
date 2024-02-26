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
    int n, x;
    cin >> n;

    map<ll, ll> rep;
    for (int i = 0; i < n; i++) {
        cin >> x;
        rep[x]++;
    }

    ll res = 0;
    for (auto it = rep.begin(); it != rep.end(); it++) {
        for (auto it2 = rep.begin(); it2 != rep.end(); it2++) {
            auto [v1, r1] = *it;
            auto [v2, r2] = *it2;

            if (it == it2)  continue;

            res += (v1 - v2) * (v1 - v2) * r1 * r2;
        }
    }

    cout << res / 2 << "\n";
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