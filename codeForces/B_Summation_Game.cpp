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
    // cerr << "========\n";
    int n, k, x;
    cin >> n >> k >> x;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend() - 1);
    
    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
    }

    ll res = LONG_LONG_MIN;
    for (int i = 0; i <= k; i++) {
        // cerr << a[n] << " " << (-2 * a[min(i + x, n)]) << " " << a[i] << " " << (a[n] - 2 * a[min(i + x, n)] + a[i]) << "\n";
        res = max(res, a[n] - 2 * a[min(i + x, n)] + a[i]);
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