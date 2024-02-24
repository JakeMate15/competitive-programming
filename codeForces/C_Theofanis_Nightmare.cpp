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
    int n;
    cin >> n;

    vector<ll> a(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = n; i >= 0; i--) {
        a[i] += a[i + 1];
    }

    vector<ll> sums;
    int r = n + 1;
    for (int i = n; i >= 1; i--) {
        if (a[i] < 0) {
            ll aux = a[i + 1];
            while (a[i] < 0 && i > 0)
                i--;
            sums.push_back(a[i] - aux);
        }
        else
            sums.push_back(a[i] - a[i + 1]);
    }

    reverse(all(sums));

    ll res = 0;
    for (int i = 0; i < sz(sums); i++) {
        res += sums[i] * (i + 1);
    }

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