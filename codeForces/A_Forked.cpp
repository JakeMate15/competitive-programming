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

void sol(){
    int a, b;
    cin >> a >> b;

    vector<ii> pos(2);
    for (auto &[x, y]: pos) {
        cin >> x >> y;
    }

    set<ii> st, st1;
    vi aux = {-1 , 1};

    for (auto x: aux) {
        for (auto y: aux) {
            int i = 0;
            for (auto [x1, y1]: pos) {
                if (i) {
                    st.insert({x1 + a * x, y1 + b * y});
                }
                else {
                    st1.insert({{x1 + a * x, y1 + b * y}});
                }
                i++;
            }
        }
    }

    swap(a, b);
    for (auto x: aux) {
        for (auto y: aux) {
            int i = 0;
            for (auto [x1, y1]: pos) {
                if (i) {
                    st.insert({x1 + a * x, y1 + b * y});
                }
                else {
                    st1.insert({{x1 + a * x, y1 + b * y}});
                }
                i++;
            }
        }
    }

    int res = 0;
    for (auto x: st) {
        res += st1.count(x);
    }
    cout << res << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}