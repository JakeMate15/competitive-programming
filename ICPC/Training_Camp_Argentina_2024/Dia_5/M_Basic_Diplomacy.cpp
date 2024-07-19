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

void sol() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(m), guys(n + 1);
    vector<int> ass(m), alone(n + 1);
 
    for(int i = 0; i < m; i++) {
        int f;
        cin >> f;
        for(int j = 0; j < f; j++) {
            int x;
            cin >> x;
            v[i].push_back(x);
            guys[x].push_back(i);
        }
        if(f == 1)
            alone[v[i][0]]++;
    }
 
    int ta = (m + 1)/2;
    for(int i = 1; i <= n; i++) {
        if(alone[i] > ta) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i++) {
        if(guys[i].size() >= ta) {
            int cnt = 0;
            for(int j = 0; j < m; j++) {
                if(v[j].size() == 1) {
                    ass[j] = v[j][0];
                    if(v[j][0] == i)
                        cnt++;
                }
            }
            for(int j = 0; j < guys[i].size(); j++) {
                if(cnt == ta || ass[guys[i][j]])
                    continue;
                ass[guys[i][j]] = i;
                cnt++;
            }
            for(int j = 0; j < m; j++) {
                if(!ass[j]) {
                    if(v[j][0] != i)
                        ass[j] = v[j][0];
                    else
                        ass[j] = v[j][1];
 
                }
            }
            for(int j = 0; j < m; j++)
                cout << ass[j] << " ";
            cout << '\n';
            return;
        }
    }
 
    for(int j = 0; j < m; j++)
        cout << v[j][0] << " ";
    cout << '\n';
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

// -Wall -Wextra -Wshadow -D_GLIBCXX_ASSERTIONS -DDEBUG -ggdb3 -fmax-errors=2