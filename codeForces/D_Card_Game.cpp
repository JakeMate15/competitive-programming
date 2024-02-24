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
    int n;
    char ganador;
    cin >> n >> ganador;

    vector<string> a(n * 2);
    for (auto &x: a) {
        cin >> x;
    }

    sort(all(a), [&](string a, string b) {
        if (a[1] == b[1]) {
            return a[0] < b[0];
        }

        if (b[1] == ganador)    return true;
        if (a[1] == ganador)    return false;

        return a[1] < b[1];
    });

    n *= 2;
    vector<bool> ok(n, true);
    vector<pair<string, string>> res;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ok[i]) {
                if (ok[j] && (a[j][1] == ganador || a[i][1] == a[j][1])) {
                    res.emplace_back(a[i], a[j]);
                    ok[i] = ok[j] = false;
                    break;
                }
            }
        }
    }

    if (sz(res) != n / 2) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        for (auto [aa, bb]: res) {
            cout << aa << " " << bb << "\n";
        }
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