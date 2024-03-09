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
    string s, r;
    cin >> s >> r;

    if (s == r && s == "0") {
        cout << "OK\n";
        return;
    }

    multiset<char> st;
    for (auto x: s) {
        st.insert(x);
    }

    auto it = st.lower_bound('1');
    if (it == st.end()) {
        cout << "WRONG_ANSWER\n";
        return;
    }

    string res = "";
    res += *it;
    st.erase(it);
    for (auto x: st) {
        res += x;
    }

    cout << (res == r ? "OK" : "WRONG_ANSWER") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    //cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}