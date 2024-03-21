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

void sol() {
    int n; 
    cin >> n;
    
    vector<tuple<ll, ll, ll>> a(n);
    for (int i = 0; i < n; i++){
        ll tam, p;
        cin >> tam >> p;
        a[i] = {p, tam, i + 1};
    }

    sort(a.rbegin(), a.rend());

    int m; 
    cin >> m;
    set<pair<ll, ll>> mesas;
    for (int i = 0; i < m; i++) {
        ll w; 
        cin >> w;
        mesas.insert({w, i + 1});
    }

    vector<pair<ll, ll>> res;
    ll sum = 0; 
    for (auto [p, tam, i] : a){
        auto it = mesas.lower_bound({tam, 0});
        if (it != mesas.end()){
            res.emplace_back(i, it -> second);
            sum += p;
            mesas.erase(it);
        }
    }
 
    cout << sz(res) << " " << sum << "\n";
    for (auto [a, b]: res) {
        cout << a << " " << b << "\n";
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