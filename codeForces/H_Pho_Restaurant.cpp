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

    bool c = false, u = false;
    vector<string> a(n);
    vector<ii> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        
        b[i] = {count(all(a[i]), '0'), count(all(a[i]), '1')};
        c |= (b[i].first > 0);
        u |= (b[i].second > 0);
    }


    int res = 0;
    if (c && u) {
        for (auto [c, u]: b) {
            res += min(c, u);
        }
    }
    else {

    }

    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    // cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}