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

    vector<int> a(n * 2);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }
    sort(all(a));

    ll d = 0;
    vector<ii> res(n);
    for (int i = 0; i < n; i++) {
        res[i].first = a[i];
        res[i].second = a[i + n];
    }

    for (int i = 1; i < n; i++) {
        d += abs(res[i].first - res[i - 1].first);
        d += abs(res[i].second - res[i - 1].second);
    }

    cout << d << "\n";
    for (auto [x, y]: res) {
        cout << x << ' ' << y << "\n";
    }
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