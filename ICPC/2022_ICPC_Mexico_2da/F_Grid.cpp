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

int g[25][25], p[25][25];

void sol() {
    
    for (int i = 1; i <= 21; i++) {
        for (int j = 1; j <= 21; j++) {
            char c;
            cin >> c;
            g[i][j] = c - '0';
        }
    }   

    for (int i = 1; i <= 21; i++) {
        for (int j = 1; j <= 21; j++) {
            p[i][j] = g[i][j] + p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
        }
    }

    int res = 0;
    for (int i = 4; i <= 21; i++) {
        for (int j = 4; j <= 21; j++) {
            int aux = p[i][j] - p[i - 4][j] - p[i][j - 4] + p[i - 4][j - 4];
            res = max(res, aux);
        }
    }

    cout << res << "\n";
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