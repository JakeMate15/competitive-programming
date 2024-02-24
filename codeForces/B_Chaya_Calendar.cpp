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
    // cerr << "=============\n";
    int n;
    cin >> n;

    vector<ll> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    for (int i = 1; i < n; i++) {
        ll a1 = a[i];
        // cerr << a1 << " ";

        if (a[i] == a[i - 1]) {
            a[i] += a1;
        }
        else if (a[i] < a[i - 1]) {
            ll aux = ceil(1.0 * a[i - 1] / a[i]);
            a[i] = a[i] * aux;

            if (a[i] == a[i - 1]) {
                a[i] += a1;
            }
        }
    }
    // cerr << "\n";

    // for (auto x: a) {
    //     cerr << x << " ";
    // }
    // cerr << "\n";

    cout << a.back() << "\n";
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