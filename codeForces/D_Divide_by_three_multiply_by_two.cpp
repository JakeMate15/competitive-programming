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

map<ll, vector<ll>> g;
vector<ll> curr;

void dfs(ll nodo, map<ll, int> rep) {
    if(rep[nodo] <= 0) 
        return;
    
    curr.push_back(nodo);
    rep[nodo]--;

    for(auto u: g[nodo]) {
        if(nodo * 2 == u || nodo / 3 == u)
            dfs(u, rep);
    }

}

void sol(){
    int n;
    cin >> n;

    vector<ll> a(n);
    map<ll, int> rep;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        rep[a[i]]++;
    }

    for(int i = 0; i < n; i++) {
        ll u, v;
        u = a[i];
        v = a[i] * 2;

        if(rep[v] > 0) {
            g[u].push_back(v);
            g[v].push_back(u);
        }

        if(u % 3 == 0) {
            v = a[i] / 3;
            if(rep[v] > 0) {
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }

    }

    for(auto [u, v]: g) {
        curr.clear();

        dfs(u, rep);
        if(sz(curr) == n) {
            for(auto x: curr) {
                cout << x << " ";
                
            }
            return;
        } 
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t=1;
    //cin>>t;

    while(t--){
        sol();
    }

    return 0;
}