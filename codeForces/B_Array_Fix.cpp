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
    int n;
    cin >> n;

    string s;
    vector<string> arr(n);
    vector<int> res;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    reverse(all(arr));
    int ant = 101;
    for (auto x: arr) {
        int num = stoi(x);
        int n1, n2;
        if (sz(x) > 1) {
            n1 = x[0] - '0';
            n2 = x[1] - '0';
        }

        if (num <= ant || sz(x) == 1) {
            res.push_back(num);
            ant = num;
        }
        else {
            res.push_back(n2);
            res.push_back(n1);
            
            ant = n2;
        }
    }
    reverse(all(res));

    // for (auto x: res) {
    //     cerr << x << " ";
    // }
    // cerr << "\n";

    
    cout << (is_sorted(all(res)) ? "YES" : "NO") << "\n";

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