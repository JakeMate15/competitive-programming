#include<bits/stdc++.h>
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl              cout << "\n";
#define u_map           gp_hash_table
#define uid(a, b)       uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template <typename T> using ordered_multi_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

void sol(){
    int n, m, d;
    cin >> n >> m >> d;
    
    vector<int> s(m + 2);
    for (int i = 1; i <= m; i++) {
        cin >> s[i];
    }
    s[0] = -d + 1;
    s[m + 1] = n + 1;
    
    int sum = 0;
    for (int i = 1; i <= m + 1; i++) {
        sum += (s[i] - s[i - 1] - 1) / d;
    }
    
    int ans = n + 1;
    int cnt = 0;
    
    for (int i = 1; i <= m; i++) {
        int res = sum;
        res -= (s[i] - s[i - 1] - 1) / d;
        res -= (s[i + 1] - s[i] - 1) / d;
        res += (s[i + 1] - s[i - 1] - 1) / d;
        res += m - 1;
        if (res < ans) {
            ans = res;
            cnt = 1;
        } else if (res == ans) {
            cnt += 1;
        }
    }
    cout << ans << " " << cnt << "\n";

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