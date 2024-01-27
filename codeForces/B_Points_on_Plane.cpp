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

ll g (ll n) {
    return (n * (n + 1)) / 2;
}

void sol(){
    cerr << "========\n";
    ll n;
    cin >> n;

    ll lo = 0, hi = n + 1;
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        cerr << lo << " " << hi << " " << mid << "\n";

        ll ok = 8 * g(mid) - 4 * n;
        cerr << ok << "\n";
        if (ok >= n)    hi = mid;
        else            lo = mid;
    }
    cerr << hi << "\n";
    ll res1 = (hi * 2) - 1;

    cerr << "-------------\n";

    lo = 0, hi = n + 1;
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        cerr << lo << " " << hi << " " << mid << "\n";

        ll ok = 8 * g(mid);
        cerr << ok << "\n";
        if (ok >= n)    hi = mid;
        else            lo = mid;
    }
    ll res2 = 2 * (hi - 1);
    cerr << hi << "\n";

    cout << min(res1, res2) << "\n";
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