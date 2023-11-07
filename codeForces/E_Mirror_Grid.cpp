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
const int MX = 2e5 + 5;

void sol(){
    int n;
    cin >> n;

    vector<string> a(n);
    for(auto &x: a) {
        cin >> x;
    }

    int res = 0;
    for(int i = 0; i < n / 2; i++) {
        for(int j = 0; j < n / 2; j++) {
            map<char, int> mp;
            mp[a[i][j]]++;
            mp[a[j][n - 1 - i]]++;
            mp[a[n - 1 - i][n - 1 - j]]++;
            mp[a[n - 1 - j][i]]++;

            int mx = max(mp['0'], mp['1']);
            res += (4 - mx);
        }
    }

    if(n & 1) {
        int j = n / 2;
        for(int i = 0; i < n / 2; i++) {
            map<char, int> mp;

            mp[a[i][j]]++;
            mp[a[j][n - 1 - i]]++;
            mp[a[n - 1 - i][n - 1 - j]]++;
            mp[a[n - 1 - j][i]]++;

            int mx = max(mp['0'], mp['1']);
            res += (4 - mx);
        }
    }

    cout << res << "\n";
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