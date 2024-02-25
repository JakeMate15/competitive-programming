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
    string s;
    cin >> n >> k >> s;

    vector<bool> ok(n);
    map<char, vector<int>> mp;
    for (int i = n - 1; i >= 0; i--) {
        mp[s[i]].push_back(i);
    }

    for (int i = 0; i < k; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            if (!sz(mp[c])) continue;

            int idx = mp[c].back();
            ok[idx] = true;
            mp[c].pop_back();
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!ok[i]) cout << s[i];
    }
    nl;
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