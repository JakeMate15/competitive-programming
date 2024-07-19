#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multi_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define all(v)          v.begin(), v.end()
#define rall(v)         v.rbegin(), v.rend()
#define sz(a)           (int)a.size()

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

void sol() {
    int n, a, b;
    cin >> n >> a >> b;

    ll ans = 0;
    map<ll, int> vals;
    map<ii, int> pendiente;
    
    for(int i = 0; i < n; i++){
        int x, vx, vy;
        cin >> x >> vx >> vy;

        ll e = 1ll * a * vx - vy;
        ans += vals[e];
        ans -= pendiente[{vx, vy}];
        vals[e]++;
        pendiente[{vx,vy}]++;
    }

    cout << 2ll * ans << endl;
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