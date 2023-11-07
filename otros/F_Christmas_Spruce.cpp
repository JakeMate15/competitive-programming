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
vector<int> hojas;
vector<bool> esHoja;

void dfs(int nodo, int padre) {

    for(auto u: arbol[nodo]) {
        if(u == padre) {
            if(sz(arbol[nodo]) == 1) {
                hojas[nodo] = 1;
                esHoja[nodo] = true;
            }
        }
        else{
            dfs(u, nodo);
        }
    }
}

void dfs2(int nodo, int padre) {

    for(auto u: arbol[nodo]) {
        if(u != padre) {
            dfs2(u, nodo);
            if(esHoja[u]) {
                hojas[nodo] += hojas[u];
            }
        }   
    }

}

void sol(){
    int n;
    cin >> n;

    arbol.clear(); arbol.resize(n + 1);
    hojas.clear(); hojas.resize(n + 1, 0);
    esHoja.clear(); esHoja.resize(n + 1, 0);
    
    for(int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        arbol[i].push_back(u);
        arbol[u].push_back(i);
    }

    dfs(1, 0);
    dfs2(1, 0);

    for(int i = 1; i <= n; i++) {
        if(!esHoja[i] && hojas[i] < 3) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";

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

