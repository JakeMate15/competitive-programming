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

void sol() {
    int n, a, b;
    cin >> n >> a >> b;

    int mn = INT_MAX;
    multiset<int> st;
    for (int i = 0; i < n * n; i++) {
        int x;
        cin >> x;
        st.insert(x);
        mn = min(mn, x);
    }

    vvi mat(n, vi(n));
    mat[0][0] = mn;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0)   continue;
            
            if (i == 0) 
                mat[i][j] = mat[i][j - 1] + b;
            else if (j == 0)    
                mat[i][j] = mat[i - 1][j] + a;
            else 
                mat[i][j] = mat[i - 1][j - 1] + b + a;
        }
    }

    for (auto x: mat) {
        for (auto y: x) {
            if (st.count(y) == 0) {
                cout << "NO\n";
                return;
            }
            st.erase(st.find(y));
        }
    }

    cout << "YES\n";
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