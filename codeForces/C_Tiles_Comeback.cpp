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
    int n, k;
    cin >> n >> k;
    
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    
    if (c[0] == c[n - 1]) {
        if (count(c.begin(), c.end(), c[0]) >= k) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }
    
    int c1 = 0;
    int c2 = count(c.begin(), c.end(), c[n - 1]);
    for (int i = 0; i < n; i++) {
        c1 += (c[0] == c[i]);
        c2 -= (c[n - 1] == c[i]);
        if (c1 >= k && c2 >= k) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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