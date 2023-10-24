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

void sol() {
    int n, m;
    cin >> n >> m;
    
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    
    vector<vector<array<int, 2>>> adj(n + m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'U') {
                adj[i].push_back({i + 1, j});
                adj[i + 1].push_back({i, j});
            }
            if (s[i][j] == 'L') {
                adj[n + j].push_back({n + j + 1, i});
                adj[n + j + 1].push_back({n + j, i});
            }
        }
    }
    for (int i = 0; i < n + m; i++) {
        if (adj[i].size() % 2) {
            cout << "-1\n";
            return;
        }
    }
    
    auto dfs = [&](auto self, int x, int y, int z) -> void {
        while (!adj[x].empty()) {
            auto [i, j] = adj[x].back();
            adj[x].pop_back();
            if ((x < n ? s[x][j] : s[j][x - n]) == '.') {
                continue;
            }
            if (x < n) {
                s[x][j] = s[i][j] = '.';
            } else {
                s[j][x - n] = s[j][i - n] = '.';
            }
            self(self, i, x, j);
        }
        if (y != -1) {
            if (x < n) {
                s[x][z] = 'W';
                s[y][z] = 'B';
            } else {
                s[z][x - n] = 'W';
                s[z][y - n] = 'B';
            }
        }
    };
    for (int i = 0; i < n + m; i++) {
        dfs(dfs, i, -1, -1);
    }
    
    for (int i = 0; i < n; i++) {
        cout << s[i] << "\n";
    }
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