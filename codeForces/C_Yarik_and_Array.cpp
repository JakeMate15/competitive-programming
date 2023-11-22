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

ll mSS(const std::vector<ll>& nums) {
    ll maxSum = nums[0];
    ll currentSum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;

}

void sol(){
    int n;
    cin >> n;

    vector<ll> a(n);
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> aux = {a[0]}; 
    vector<vector<ll>> nc; 

    for(int i = 1; i < n; i++) {
        if(abs(a[i] % 2) != abs(aux.back() % 2)) { 
            aux.push_back(a[i]); 
        }
        else {
            nc.push_back(aux); 
            aux.clear(); 
            aux.push_back(a[i]); 
        }
    }
    if(!aux.empty()) {
        nc.push_back(aux);
    }

    // for(auto x: nc) {
    //     for(auto y: x) {
    //         cerr << y << " ";
    //     }
    //     cerr << "\n";
    // }

    ll res = LONG_LONG_MIN;
    for(auto x: nc) {
        res = max(res, mSS(x));
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