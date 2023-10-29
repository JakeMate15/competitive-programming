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

bool twoSum(vector<int> a, int meta, int ignora) {
    bool f = false;
    set<int> mp;
    int aux;

    for(int i = 0; i < sz(a); i++) {
        if(a[i] == ignora) {
            if(!f) {
                f = true;
                continue;
            }
        }

        aux = meta - a[i];
        if(mp.count(aux)) {
            return true;
        }
        mp.insert(a[i]);
    }

    return false;
}

void sol(){
    //cerr << "======================\n";
    int n;
    cin >> n;

    vector<int> a(n);
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a[i] = s[sz(s) - 1] - '0';
        mp[a[i]]++;
    }

    vector<int> sumas = {3, 13, 23};
    for(auto [num, rep]: mp) {
        for(auto sum: sumas) {
            //cerr << sum - num << " " << num << "\n";
            if(twoSum(a, sum - num, num)) {
                cout << "YES\n";
                return;
            }
        }
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