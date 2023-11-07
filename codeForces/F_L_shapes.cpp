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

int n, m;
char g[55][55];
bool vis[55][55];

void dfs(int i, int j, set<int> &is, set<int> &js, int &cuantos) {
    if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || g[i][j] != '*')
        return;

    vis[i][j] = true;
    cuantos++;
    
    is.insert(i);
    js.insert(j);

    dfs(i + 1, j, is, js, cuantos);
    dfs(i, j + 1, is, js, cuantos);
    dfs(i - 1, j, is, js, cuantos);
    dfs(i, j - 1, is, js, cuantos);

    dfs(i + 1, j + 1, is, js, cuantos);
    dfs(i - 1, j - 1, is, js, cuantos);
    dfs(i - 1, j + 1, is, js, cuantos);
    dfs(i + 1, j - 1, is, js, cuantos);
}


void sol(){
    //cerr << "========================\n";
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> g[i][j];
            vis[i][j] = false;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && g[i][j] == '*') {
                //cerr << i << " " << j << "\n";
                int cuantos = 0;
                set<int> is, js;

                dfs(i, j, is, js, cuantos);
                
                if(cuantos != 3) {
                    cout << "NO\n";
                    return;
                }

                int mni = *is.begin(), mxi = *prev(is.end());
                int mnj = *js.begin(), mxj = *prev(js.end());
                int l = abs(mni - mxi) + 1, h = abs(mnj - mxj) + 1;
                //cerr << l << "\t" << h << "\n";
                if(l != 2 || h != 2) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }

    cout << "YES\n";

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