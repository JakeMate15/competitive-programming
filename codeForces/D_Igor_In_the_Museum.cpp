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
const int MX = 1000 + 5;

char g[MX][MX];
bool vis[MX][MX];
const int dr[] = {1,-1,0,0,1,-1,-1,1};
const int dc[] = {0,0,1,-1,1,1,-1,-1};
int n, m, q;

bool ok(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m && !vis[x][y];
}

unordered_map<int, int> res;
map<ii, int> donde;
void dfs (int x, int y, int comp) {
    if(!ok(x, y, n, m)) return;

    if (g[x][y] == '*') {
        res[comp]++;
        return;
    }

    vis[x][y] = true;
    donde[{x, y}] = comp;
    for (int i = 0; i < 4; i++) {
        dfs(x + dr[i], y + dc[i], comp);
    }
}

void sol(){
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            vis[i][j] = false;
        }
    }

    int c = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && g[i][j] != '*') {
                dfs(i, j, c++);
            }
        }
    }

    while (q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        cout << res[donde[{u, v}]] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}