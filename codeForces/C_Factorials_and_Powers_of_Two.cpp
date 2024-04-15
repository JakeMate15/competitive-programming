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
const ll MX = 1e12 + 5;

ll fact[20];
map<ll, int> cnt;

void sol() {
    ll n;
    cin >> n;

    int res = __builtin_popcountll(n);
    for (auto [a, b]: cnt) {
        int curr = b;
        ll rem = n - a;
        
        if (rem < 0)    break;
        curr += __builtin_popcountll(rem);
        res = min(res, curr);
    }

    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cnt.clear();

    fact[0] = 1;
    for (int i = 1; i < 20 && fact[i - 1] < MX; i++) {
        fact[i] = fact[i - 1] * i;
    }

    for (int msk = 0; msk <= (1 << 15); msk++) {
        ll v = 0;
        for (int i = 0; i < 15; i++) {
            if (msk & (1 << i)) {
                v += fact[i];
            }
        }

        if (cnt[v] == 0)
            cnt[v] = INT_MAX;

        cnt[v] = min(cnt[v], __builtin_popcountll(msk));
    }

    cnt[0] = 0;

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}