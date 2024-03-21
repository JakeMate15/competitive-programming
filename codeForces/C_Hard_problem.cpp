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
const int MX = 1e5 + 5;

int c[MX], n;
string palabras[MX];
ll dp[MX][2];

ll go (int i, int invertido) {
    if (i == n)
        return 0;

    ll &mem = dp[i][invertido];
    if (mem != -1)
        return mem;

    string anterior = palabras[i - 1];
    if (invertido) 
        reverse(all(anterior));

    ll res = 1E18;
    string act = palabras[i];

    if (anterior <= act)
        res = min(res, go(i + 1, 0));

    reverse(all(act));
    if (anterior <= act) 
        res = min(res, go(i + 1, 1) + c[i]);

    return mem = res;
}


void sol() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> c[i];
        dp[i][0] = dp[i][1] = -1;
    }

    for (int i = 0; i < n; i++) {
        cin >> palabras[i];
    }

    ll res = min(go(1, 0), go(1, 1) + c[0]);
    cout << (res == 1E18 ? -1 : res) << "\n";

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