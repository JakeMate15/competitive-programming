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

//cuidado con el overflow en k * p

void sol() {
    ll n, k;
    cin >> n >> k;

    vector<int> vida(n);
    ll x;
    for (int i = 0; i < n; i++) {
        cin >> vida[i];
    }

    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        cin >> x;
        mp[abs(x)] += vida[i];
    }

    ll balas = 0, sum = 0;
    for (auto [p, v]: mp) {
        sum += v;

        if (sum > k * p) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}