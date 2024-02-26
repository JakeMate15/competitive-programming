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

// const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

ll mod(ll a, ll b){
    ll ans = a % b;
    if(ans < 0) ans += b;
    return ans;
}

void sol() {
    int n, q;
    string s;
    cin >> n >> q >> s;

    ll aux = 0;
    while (q--) {
        int op, x;
        cin >> op >> x;

        if (op == 1) {
            aux = (aux - x + n) % n;
        }
        else {
            x--;
            cout << s[(aux + x) % n] << "\n";
        }

        // cerr << aux << "\n";
    }
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