#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl              cout << "\n";
#define u_map           gp_hash_table
#define uid(a, b)       uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multi_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

void sol(){
    int n, q;
    cin >> n >> q;

    vector<vector<ll>> mat(1005, vector<ll>(1005));
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        mat[a][b] += 1LL * a * b;
    }

    for(int i = 1; i < 1002; i++) {
        for(int j = 1; j < 1002; j++) {
            mat[i][j] += mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
        }
    }

    while(q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        ll res = mat[c - 1][d - 1] - mat[c - 1][b] - mat[a][d - 1] + mat[a][b];
        cout << res << "\n";
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t=1;
    cin>>t;

    while(t--){
        sol();
    }

    return 0;
}