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

string dir;
int n, m, xi, yi, xf, yf;
vector<vector<int>> g;

map<string, int> dirs = {{"DR", 0}, {"DL", 1}, {"UL", 3}, {"UR", 2}};
map<string, string> oEs = {{"DR", "UL"}, {"DL", "UR"}, {"UL", "DR"}, {"UR", "DL"}};

map<string, string> oX = {{"DR", "UR"}, {"DL", "UL"}, {"UL", "DL"}, {"UR", "DR"}};
map<string, string> oY = {{"DR", "DL"}, {"DL", "DR"}, {"UL", "UR"}, {"UR", "UL"}};

int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};

bool ok(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

bool esquina(int i, int j) {
    if(i == 0 && j == 0)
        return true;
    if(i == 0 && j == m - 1)
        return true;
    if(i == n - 1 && j == 0)
        return true;
    if(i == n - 1 && j == m - 1)
        return true;
    return false;
}

int dfs(int i, int j, string dir, int pasos) {
    //cerr << i << " " << j << "\n";
    if(!ok(i, j)) {
        return -1;
    }

    // EStamos en el punto
    if(i == (xf - 1) && j == (yf - 1)) {
        // cerr << "llegue\n";
        return pasos;
    }   

    int d = dirs[dir];

    // Ya estamos en un borde o esquina
    if(!ok(i + dx[d], j + dy[d])) {
        // cerr << "pared \n";
        pasos++;
        if(esquina(i, j)) {
            if(g[i][j] > 5) {
                // cerr << "esquina\n";
                return -1;
            }
            dir = oEs[dir];
        } 
        else if(i == 0 || i == n - 1) {
            dir = oX[dir];
        }
        else {
            dir = oY[dir];
        }
        
        d = dirs[dir];
    }
    d = dirs[dir];
    g[i][j]++;

    return dfs(i + dx[d], j + dy[d], dir, pasos);
}


void sol(){
    //cerr << "===============\n";
    cin >> n >> m >> xi >> yi >> xf >> yf >> dir;

    g.clear();
    g.resize(n + 1, vector<int>(m + 1));

    cout << dfs(xi - 1, yi - 1, dir, 0) << "\n";
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    //cout << fixed << setprecision(10);

    int t=1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}