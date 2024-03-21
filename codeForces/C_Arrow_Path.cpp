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
const int MX = 2e5 + 5;

const int dr[] = {1,-1,0,0,1,-1,-1,1};
const int dc[] = {0,0,1,-1,1,1,-1,-1};

bool ok(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void sol() {
    int n;
    cin >> n;

    vector<vector<char>> g(2, vector<char>(n));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }


    vector<vector<bool>> vis(2, vector<bool>(n));
    queue<ii> q;
    q.emplace(0, 0);
    vis[0][0] = true;

    while (!q.empty()) {
        ii curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int x = curr.first + dr[i], y = curr.second + dc[i];
            if (!ok(x, y, 2, n) || vis[x][y]) continue;
            vis[x][y] = true;
            y += (g[x][y] == '>' ? 1 : -1);
            if (!ok(x, y, 2, n) || vis[x][y]) continue;

            vis[x][y] = true;
            q.emplace(x, y);
        }
    }

    // for (auto x: vis) {
    //     for (auto y: x) {
    //         cerr << y << " ";
    //     }
    //     cerr << "\n";
    // }

    cout << (vis[1][n - 1] ? "YES" : "NO") << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}