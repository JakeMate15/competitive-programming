#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../algoDebug.h"
    #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#endif

#define forn(i,n)       for(int i=0; i<n; i++)
#define forr(i,a,n)     for(int i=a; i<n; i++)
#define fore(i,a,n)     for(int i=a; i<=n; i++)
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
const int mx = 2e5 + 5;

vector<int> entrada, g[mx], res;
int vis[mx], orden[mx];

bool cmp(int a, int b) {
    return orden[a] < orden[b];
}

void bfs(int s) {
    queue<int> q;
    vis[s] = true;
    q.push(s);
    while(!q.empty()) {
        int u = q.front(); 
        q.pop();
        res.push_back(u);
        for(auto v: g[u]) {
            if(!vis[v]) {
                q.push(v);
                vis[v] = 1;
            }
        }
    }
}

void sol() {
    int n;
    cin >> n;

    forn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    forn(i, n) {
        int x;
        cin >> x;
        entrada.push_back(x);
        orden[x] = i;
    }

    fore(i, 1, n) {
        sort(all(g[i]), cmp);
    }

    bfs(1);
    
    forn(i,n) {
        if(res[i] != entrada[i]) {
            debln("No");
            return;
        }
    }

    debln("Yes");
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