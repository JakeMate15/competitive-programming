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

const int mod = 1e9 + 7;
const int mx = 1e3 + 5;

char m[mx][mx];

void sol(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }

    int res = 0;
    for(int i = 0; i < n / 2; i++) {
        for(int j = 0; j < n /2 ; j++) {
            vector<char> a = {m[i][j], m[j][n - 1 -i], m[n - 1 - i][n - 1 - j], m[n - 1 - j][i]};
            res += *max_element(all(a)) * 4 - accumulate(all(a), 0);
        }
    }

    debln(res);
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