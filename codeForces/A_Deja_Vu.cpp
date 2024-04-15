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
    int n, q;
    cin >> n >> q;

    set<int> st;
    vector<int> a(n), qq;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }    

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;

        if (st.count(x) == 0) {
            qq.push_back(x);
            st.insert(x);
        }
    }

    for (auto x: qq) {
        for (int i = 0; i < n; i++) {
            if (a[i] % (1 << x) == 0) {
                a[i] += (1 << (x - 1));
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
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