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
    //cerr << "===========================\n";
    ll n, k;
    cin >> n >> k;

    multiset<pair<ll, int>> a;
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        x = x % k == 0 ? k : x % k;
        a.insert({x, -(i + 1)});
    }

    while(sz(a) > 1) {
        auto ult = prev(a.end());
        auto pen = prev(ult);

        auto ultV = *ult;
        auto penV = *pen;

        ll dif = max(ultV.first - penV.first, 1LL);
        //cerr << ultV.first << " " << penV.first << " " << dif << "\n";
        ll veces = ceil((1.0 * dif) / k);
        ultV.first -= veces * k;
        //cerr << ultV.first << " " << penV.first << " " << dif << "\n";

        if(ultV.first <= 0) {
            cout << -1 * ultV.second << " ";
            a.erase(ult);
        }
        else {
            a.erase(ult);
            a.insert(ultV);
        }
    }

    cout << -1 * (*a.begin()).second << "\n";
    //cerr << "\n\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << fixed << setprecision(10);

    int t=1;
    cin>>t;

    while(t--){
        sol();
    }

    return 0;
}