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

bool ok (int k, int n, vector<int> a) {
    vector<int> b(n);
    for (int i = 0; i < k; i++) {
        b[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        b[i % k] ^= a[i];
    }
    for (int i = 1; i < k; i++) {
        if (b[i] != b[0])
            return false;
    }

    return true;
}

void sol() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        a[i] = c - '0';
        a[i] ^= 1;
    }

    for (int i = n; i >= 1; i--) {
        if (ok(i, n, a)) {
            cout << i << "\n";
            return;
        }
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}