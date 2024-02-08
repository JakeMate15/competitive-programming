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

void sol(){
    ll a, b, r;
    cin >> a >> b >> r;

    if (b > a) {
        swap(b, a);
    }

    ll x = 0;
    bool f = true;
    for (int i = 60; i >= 0; i--) {
        ll pot = (1LL << i);
        bool ba = a & pot;
        bool bb = b & pot;

        if (ba != bb) {
            if (f) {
                f = false;
            }
            else {
                if ((x | pot) <= r && ba) {
                    x |= pot;
                    a ^= pot;
                    b ^= pot;
                }
            }
        }
    }

    cout << a - b << "\n";   
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