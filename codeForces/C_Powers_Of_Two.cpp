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

void sol(){
    int n, k;
    cin >> n >> k;

    priority_queue<int> res;
    for (int i = 0; i < 32; i++) {
        if (1 << i & n) {
            res.push(1 << i);
        }
    }

    if (k < __builtin_popcount(n)) {
        cout << "NO\n";
        return;
    }

    while (sz(res) < k && res.top() > 1) {
        int curr = res.top();
        res.pop();

        res.push(curr / 2);
        res.push(curr / 2);
    }

    if (sz(res) < k) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    while (!res.empty()) {
        cout << res.top() << " ";
        res.pop();
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}