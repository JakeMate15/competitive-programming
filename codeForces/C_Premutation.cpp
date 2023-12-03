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
    // cerr << "==============\n";
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n - 1));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 1; j++) {
            cin >> a[i][j];
        }
    }

    map<int, vector<int>> aux;
    for(int i = 0; i < n; i++) {
        aux[a[i][0]].push_back(i);
    }

    int donde = 0, mn = INT_MAX;
    for(auto [i, v]: aux) {
        // cerr << i << " ";
        // for(auto x: v)
        //     cerr << x << " ";
        // cerr << "\n";

        // if(sz(v) < mn) {
        //     mn = sz(v);
        //     donde = i;
        // }
        if(sz(v) == 1) {
            donde = v[0];
            break;
        }
    }


    for(int i = 0; i < n; i++) {
        if(i != donde) {
            cout << a[i][0] << " ";
            break;
        }
    }

    auto res = a[donde];

    for(auto x: res) {
        cout << x << " ";
    }
    nl;
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