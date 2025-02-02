#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t n, m, k;
    cin >> n >> m >> k;

    int64_t sum = 0;
    vector<int64_t> arr(n);
    ordered_set<pair<int64_t, int>> st;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        st.insert({arr[i], i});
    }

    cerr << sum << " " << k - sum << "\n";
    for (auto [v, _]: st) {
        cerr << v << " ";
    }
    cerr << "\n\n";

    for (int i = 0; i < n; i++) {
        st.erase({arr[i], i});

        cerr << "==================================\n";
            for (auto [v, _]: st) {
            cerr << v << " ";
        }
        cerr << "\n";

        int64_t lo = -1, hi = k - sum + 1;
        while (lo + 1 < hi) {
            int64_t mid = (lo + hi) / 2;
            int p = st.order_of_key({arr[i] + mid + 1, 1E12 + 5});

            cerr << "-----------------------\n";
            cerr << lo << " " << hi << " " << mid << "\n";
            cerr << arr[i] + mid << " " << p << " " << n - p - 1 << "\n";

            if (n - p - 1 < m && prev(st.end())->second + ) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        cout << (hi == k - sum + 1 ? -1 : hi) << " \n"[i == n - 1];
        st.insert({arr[i], i});
    }

    return 0;
}