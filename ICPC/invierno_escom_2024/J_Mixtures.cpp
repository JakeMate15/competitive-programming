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

ll dp[105][105];
ll arr[105];

ll sol(int a, int b) {
    if (dp[a][b] != -1)  return dp[a][b] ;
    if (a == b)          return 0;

    ll res = dp[a][b];
    for (int k = a; k + 1 <= b; k++) {
        ll aux = sol(a, k) + sol(k + 1, b) + ((arr[k] - arr[a - 1]) % 100) * ((arr[b] - arr[k]) % 100);
        if (res == -1 || aux < res) {
            res = aux;
        }
    }

    return dp[a][b] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int n;

    while(cin >> n) {
        memset(dp, -1, sizeof(dp));
        memset(arr, 0, sizeof(arr));
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            arr[i] += arr[i - 1];
        }

        // for (int i = 0; i <= n; i++) {
        //     cerr << arr[i] << " \n"[i == n];
        // }

        cout << sol(1, n) << "\n";
    }

    return 0;
}