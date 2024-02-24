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
    int n, x;
    cin >> n;

    vector<ii> arr;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> x;
        arr.emplace_back(x, -1);
    }
    for (int i = 0; i < n; i++) {
        cin >> x;
        arr.emplace_back(x, 1);
    }
    for (auto &x: c) {
        cin >> x;
    }

    sort(all(arr));

    stack<int> st;
    vector<int> dif;
    for (auto [v, p]: arr) {
        if (p < 0) {
            st.push(v);
        }
        else {
            dif.push_back(v - st.top());
            st.pop();
        }
    }

    sort(all(dif));
    sort(all(c), greater());

    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += (1LL * dif[i] * c[i]);
    }

    cout << res << "\n";

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}