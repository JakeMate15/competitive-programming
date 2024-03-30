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
    ll n;
    cin >> n;

    vector<ll> nums(n - 1);
    set<ll> st;
    for(int i = 1;i <= n; i++) {
        st.insert(i);
    }
    for(auto &c: nums) {
        cin>>c;
    }

    ll last = 0;
    ll bad = 0;
    for(int i = 0; i < n - 1; i++){
        ll x = nums[i] - last;
        if(st.count(x) == 0)    bad = x;
        else st.erase(x);
        last = nums[i];
    }

    if(sz(st) == 1){
        cout << "YES" << "\n";
        return;
    }
    if(sz(st) != 2){
        cout << "NO" << endl;
        return;
    }

    ll a1 = *st.begin();
    st.erase(st.begin());
    ll a2 = *st.begin();

    cout << ((a1 + a2 == bad) ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}