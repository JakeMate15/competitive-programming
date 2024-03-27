#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define sz(a)   (int)a.size()
#define all(a)  a.begin(), a.end()

template <typename T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int q;
    cin >> q;

    ordered_set<ll> os;
    vector<ll> nc(q + 10);

    for(int i = 1; i <= q; i++) {
        ll op, x, y;
        cin >> op;

        if (op == 1) {
            cin >> x;

            nc[i] = x;
            os.insert(x);
        }
        else if (op == 2) {
            cin >> x;

            os.erase(os.upper_bound(nc[x]));
        }
        else if (op == 3) {
            cin >> y >> x;

            os.erase(os.upper_bound(nc[y]));
            nc[y] += x; 
            os.insert(nc[y]);
        }
        else {
            cin >> x;

            cout << os.order_of_key(nc[x]) << "\n";
        }
    }
}