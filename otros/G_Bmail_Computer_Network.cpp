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

vector<vector<int>> arbol;
vector<int> padres;

void dfs(int nodo, int padre) {
    padres[nodo] = padre;
    //cerr << nodo << " " << padre << "\n";

    for(auto u: arbol[nodo]) {
        if(u != padre) {
            dfs(u, nodo);
        }
    }

}

void sol(){
    int n;
    cin >> n;

    arbol.resize(n + 1);
    padres.resize(n + 1);

    for(int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        arbol[i].push_back(u);
        arbol[u].push_back(i);
    }

    dfs(1, 0);
    // for(auto x: padres) {
    //     cerr << x << " ";
    // }
    vector<int> res = {n};
    int actual = n;
    while(actual != 1) {
        res.push_back(padres[actual]);
        actual = padres[actual];
    }

    reverse(all(res));
    
    for(auto x: res) {
        cout << x << " ";
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