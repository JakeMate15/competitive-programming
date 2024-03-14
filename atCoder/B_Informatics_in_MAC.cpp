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
    // cerr << "==============\n";
    int n;
    cin >> n;

    vector<int> a(n);
    set<int> st;
    for (auto &x: a) {
        cin >> x;
        st.insert(x);
    }

    int mex = 0;
    for (int i = 0; ; i++) {
        if (!st.count(i)) {
            mex = i;
            break;
        }
    }

    vector<ii> res;
    ordered_set<int> os;
    int cmex = 0;
    for (int i = 0; i < n; i++) {
        int inicio = i, fin = i;
        while (i < n) {
            os.insert(a[i]);
            if (os.order_of_key(mex) == mex) {
                fin = i;
                res.emplace_back(inicio, fin);
                os.clear();
                break;
            }
            i++;
        }
    }

    if (sz(res) == 1) {
        cout << "-1\n";
    } 
    else {
        cout << sz(res) << "\n";
        for (int i = 0; i < sz(res); i++) {
            int a = res[i].first + 1, b = res[i].second + 1;
            if (i == sz(res) - 1) {
                b = n;
            }

            cout << a << " " << b << "\n";
        }
    }

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