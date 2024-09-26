#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
            int,
            null_type,
            less_equal<int>,
            rb_tree_tag,
            tree_order_statistics_node_update
        > ordered_set;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, x;
    cin >> n >> k;

    ordered_set ors;
    vector<int> a(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];

        if (i < k) {
            ors.insert(a[i]);
        }
    }

    for(int i = k - 1; i < n; i++) {
        cout << *ors.find_by_order((k - 1) / 2) << " \n"[i == n - 1];
        ors.erase(ors.upper_bound(a[i - k + 1]));
        ors.insert(a[i + 1]);
    }   

    return 0;
}