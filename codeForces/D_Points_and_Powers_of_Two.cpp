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

    map<int, int> rep;
    int mx = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin >> x;
        rep[x]++;
        mx = max(mx, x);
    }

    if (sz(rep) == 1) {
        cout << 1 << "\n";
        cout << mx;
        return;
    }

    set<pair<int, int>> res;
    ll tam = 0;
    for (auto [v, r]: rep) {
        // cerr << "===============\n";
        ll cur = 1;
        while (v + cur <= mx) {
            // ll cTam = r;
            set<pair<int, int>> cR = {{v, r}};
            // cerr << v << "\n";

            if (rep.count(v + cur)) {
                // cTam += rep[v + cur];
                cR.insert({v + cur, rep[v + cur]});
                // cerr << v + cur << "\n";
                if (rep.count(v + 2 * cur)) {
                    // cTam += rep[v + cur * cur];
                    cR.insert({v + 2 * cur, rep[v + 2 * cur]});
                }
            }
            // cerr << "\n" << sz(cR) << "\n";
            // for (auto [aa, bb]: cR) {
            //     cerr << aa << " " << bb << "\n";
            // }
            // cerr << "---------------\n";
            if (sz(cR) > tam) {
                // res.clear();
                tam = sz(cR);
                res = cR;
            }

            cur *= 2;
        }
    }

    cout << tam << "\n";
    for (auto [v, r]: res) {
        for (int i = 0; i < r; i++) {
            cout << v << " ";
        }
    }

}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    //cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}