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
const ll inf = LONG_LONG_MAX;

void sol() {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (k >= 3) {
        cout << 0 << "\n";
        return;
    }

    vector<ll> aux;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            aux.push_back(abs(a[i] - a[j]));
        }
    }

    sort(all(aux));
    sort(all(a));
    ll res = min(a[0], aux[0]);

    if (k == 1) {
        cout << res << "\n";
        return;
    }

    for (auto x: a) {
        auto it = lower_bound(all(aux), x);

        if (it != aux.end()) {
            res = min(res, abs(*it - x));
        }
        if (it != aux.begin()) {
            res = min(res, abs(*prev(it) - x));
        }

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