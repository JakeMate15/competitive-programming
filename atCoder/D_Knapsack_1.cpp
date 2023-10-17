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
const int MX = 100 + 5, W = 1e5 + 5;

int pesos[MX], beneficio[MX], n, w;
vector<vector<ll>> mem(W, vector<ll>(MX, -1));

ll dp(int pRestante, int i) {
    if(pRestante <= 0 || i > n) 
        return 0;

    ll &a = mem[pRestante][i];
    if(a != -1)
        return a;

    if(pesos[i] > pRestante)
        return a = dp(pRestante, i + 1);
    

    return a = max(dp(pRestante - pesos[i], i + 1) + beneficio[i], dp(pRestante, i + 1));
}

void sol(){
    cin >> n >> w;

    for(int i = 1; i <= n; i++) {
        cin >> pesos[i] >> beneficio[i];
    }

    debln(dp(w, 1));
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