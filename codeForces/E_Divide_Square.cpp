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
const int mx = 1e6 + 5;

vector<int> entrada[mx], salida[mx];
pair<int, int> arr[mx];

struct FenwickTree{
    int N;
    vector<ll> bit;

    FenwickTree(int N): N(N){
        bit.resize(N, 0);
    }

    void update(int pos, ll value){
        while(pos < N){
            bit[pos] += value;
            pos |= pos + 1;
        }
    }

    ll query(int r){
        ll res = 0;
        while(r >= 0){
            res += bit[r];
            r = (r & (r + 1)) - 1;
        }
        return res;
    }

    ll query(int l, int r){
        return query(r) - query(l - 1);
    }
};

void sol() {
    int n, m;
    cin >> n >> m;

    ll res = 1;
    for (int i = 0; i < n; i++) {
        int y, x1, x2;
        cin >> y >> x1 >> x2;

        entrada[x1].push_back(y);
        salida[x2].push_back(y);

        res += (x1 == 0 && x2 == 1e6);
    }

    
    for (int i = 0; i < m; i++) {
        int x, y1, y2;
        cin >> x >> y1 >> y2;

        arr[x] = {y1, y2};
        res += (y1 == 0 && y2 == 1e6);
    }

    FenwickTree st(mx);
    for (int i = 0; i <= 1e6; i++) {
        for (auto x: entrada[i]) {
            st.update(x, 1);
        }

        auto[l, r] = arr[i];
        res += st.query(l, r);

        for (auto x: salida[i]) {
            st.update(x, -1);
        }
    }

    cout << res << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    //cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}

// -Wall -Wextra -Wshadow -D_GLIBCXX_ASSERTIONS -DDEBUG -ggdb3 -fmax-errors=2