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

/*
Nota:
    Cuidado con el tipo de entrada, no leer ai con strings
    Cuidado overflow en sumas pref
*/

void sol() {
    int n;
    cin >> n;

    vector<ii> a(n);
    char c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        a[i].first = c - '0';
        a[i].second = n - (i + 1);
    }

    sort(all(a));

    vector<ll> res(n, -1);
    ll curr = 0;
    for (int i = 0; i < n && a[i].first == 0; i++) {
        curr += a[i].second - i;
        res[i] = curr;
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << " \n"[i == n - 1];
    }
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