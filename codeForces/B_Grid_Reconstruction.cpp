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

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

void sol(){
    int n;
    cin >> n;
    
    int ans[3][n + 1];
    
    ans[1][1] = 2 * n - 1;
    ans[2][n] = 2 * n;

    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            ans[1][i] = i;
            ans[2][i - 1] = i - 1;
        } else {
            ans[1][i] = n + (i - 1);
            ans[2][i - 1] = n + (i - 1) - 1;
        }
    }

    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ans[i][j] << (j == n ? '\n' : ' ');
        }
    }
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