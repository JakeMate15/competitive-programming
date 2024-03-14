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
    int n, m, x;
    cin >> n >> m >> x;
    --x; 
    set<int> st; 
    st.insert(x);

    for (int i = 0; i < m; ++i) {
        int r;
        char c;
        cin >> r >> c;
        set<int> stA;

        if (c == '?') {
            for (int pos : st) {
                stA.insert((pos + r) % n);
                stA.insert((pos - r + n) % n);
            }
        } else {
            for (int pos : st) {
                if (c == '0') { // Horario
                    stA.insert((pos + r) % n);
                } else { // Antihorario
                    stA.insert((pos - r + n) % n);
                }
            }
        }

        st = stA;
    }

    cout << sz(st) << endl;
    for (int pos : st) {
        cout << pos + 1 << " "; 
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