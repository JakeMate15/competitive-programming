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
const int MX = 1e5 + 5;

int precio[1001], pags[1001], n, dinero;
vector<vector<int>> dp(1001, vector<int>(MX, -1));

int go(int dinero, int i) {
    if(i >= n || dinero <= 0)
        return 0;
    
    int &a = dp[i][dinero];
    if(a != -1)
        return a;

    if(dinero < precio[i])
        return a = go(dinero, i + 1);

    return a = max(go(dinero, i + 1), go(dinero - precio[i], i + 1) + pags[i]);
}

void sol(){
    cin >> n >> dinero;

    for(int i = 0; i < n; i++) {
        cin >> precio[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> pags[i];
    }

    debln(go(dinero, 0));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t=1;
    //cin>>t;

    while(t--){
        sol();
    }

    return 0;
}