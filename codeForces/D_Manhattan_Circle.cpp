#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multi_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define all(v)          v.begin(), v.end()
#define rall(v)         v.rbegin(), v.rend()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '"' << x << '"';}
void __print(const string &x) {cerr << '"' << x << '"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}

template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << '}';}

void _print() {cerr << "]\n";}

template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#define RAYA            cerr << "==========================\n";
#define raya            cerr << "--------------------------\n";
#else
#define debug(x...)
#define RAYA
#define raya
#endif

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

pair<int, int> find_center(const vector<pair<int, int>>& coordinates) {
    vector<int> x_coords, y_coords;
    for (const auto& coord : coordinates) {
        x_coords.push_back(coord.first);
        y_coords.push_back(coord.second);
    }
    
    sort(x_coords.begin(), x_coords.end());
    sort(y_coords.begin(), y_coords.end());
    
    int median_x = x_coords[x_coords.size() / 2];
    int median_y = y_coords[y_coords.size() / 2];
    
    return {median_x, median_y};
}

void sol() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<pair<int, int>> coordinates;
        
        for (int i = 1; i <= n; ++i) {
            string row;
            cin >> row;
            for (int j = 1; j <= m; ++j) {
                if (row[j - 1] == '#') {
                    coordinates.emplace_back(i, j);
                }
            }
        }
        
        pair<int, int> center = find_center(coordinates);
        cout << center.first << " " << center.second << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}

// -Wall -Wextra -Wshadow -D_GLIBCXX_ASSERTIONS -DDEBUG -ggdb3 -fmax-errors=2