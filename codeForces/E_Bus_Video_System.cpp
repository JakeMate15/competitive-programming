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

bool ok (vector<int> a, int inicio, int capacidad) {
    for (auto x: a) {
        inicio += x;
        if (inicio < 0 || inicio > capacidad)    return false;
    }
    return true;
}

void sol(){
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    int lo = -1, hi = m + 1;
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;

        if (ok(a, mid, m))  lo = mid;
        else                hi = mid;
    }

    int mx = (lo == -1 ? m : lo);
    lo = -1, hi = mx + 1;
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;

        if (ok(a, mid, m))  hi = mid;
        else                lo = mid;
    }

    // cerr << lo << ' ' << hi << "\n";

    cout << max(0, mx - lo) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    // cin >> t;

    while(t--){
        sol();
    }

    return 0;
}