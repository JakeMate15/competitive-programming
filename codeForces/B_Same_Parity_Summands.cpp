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
    int n,k;
    cin>>n>>k;

    int n1 =  n - (k - 1);
    if(n1 > 0 && n1 % 2 == 1){
        cout << "YES\n";
        for(int i = 0; i < k - 1; i++) {
            cout << 1 << " ";
        }
        cout << n1 << "\n";

        return;
    }

    int n2 = n - 2 * (k - 1);
    if(n2 > 0 && n2 % 2 == 0){
        cout << "YES\n";
        for(int i = 0; i < k - 1; i++) {
            cout << 2  << " ";
        }

        cout << n2 << "\n";
        return;
    }

    cout << "NO\n";
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