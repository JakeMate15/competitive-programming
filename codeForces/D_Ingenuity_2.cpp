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

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

void sol() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    map<char, char> inv{{'N', 'S'}, {'S', 'N'}, {'E', 'W'}, {'W', 'E'}};

    int x = 0, y = 0;
    for (char c : s) {
        if (c == 'N') y += 1;
        else if (c == 'S') y -= 1;
        else if (c == 'E') x += 1;
        else if (c == 'W') x -= 1;
    }

    if (x % 2 != 0 || y % 2 != 0) {
        cout << "NO" << endl;
        return;
    }

    vector<char> ans(n, 'R');
    if (x == 0 && y == 0) {
        if (n == 2) {
            cout << "NO" << endl;
            return;
        }
        size_t pos = s.find(inv[s[0]]);
        ans[0] = ans[pos] = 'H';
    } 
    else {
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'N' && y > 0) {
                y -= 2;
                ans[i] = 'H';
            } 
            else if (s[i] == 'S' && y < 0) {
                y += 2;
                ans[i] = 'H';
            } 
            else if (s[i] == 'E' && x > 0) {
                x -= 2;
                ans[i] = 'H';
            } 
            else if (s[i] == 'W' && x < 0) {
                x += 2;
                ans[i] = 'H';
            }
        }
    }

    for (char c : ans) {
        cout << c;
    }
    cout << endl;
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