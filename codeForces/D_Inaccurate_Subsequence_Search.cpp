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
    int n, m, k;
    cin >> n >> m >> k;

    map<int, int> r1, r2;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        r1[a[i]]++;
        r2[b[i]]++;
    }

    int cnt = 0, res = 0;
    for (auto [v, r]: r2) {
        cnt += min(r1[v], r);
    }

    res += (cnt >= k);
    for (int i = m; i < n; i++) {
        cnt -= min(r1[a[i - m]], r2[a[i - m]]);
        cnt -= min(r1[a[i]], r2[a[i]]);

        r1[a[i]]++;
        r1[a[i - m]]--;

        cnt += min(r1[a[i - m]], r2[a[i - m]]);
        cnt += min(r1[a[i]], r2[a[i]]);

        res += (cnt >= k);
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