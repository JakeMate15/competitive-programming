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

    int sum = 0;
    string res = "";
    set<int> aux = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    while (sum != n) {
        set<int>::iterator it;
        if (aux.count(n - sum)) {
            it = aux.find(n - sum);
        }
        else {
            it = prev(aux.upper_bound(n - sum));
        }

        char num = '0';
        num += *it;
        aux.erase(it);
        sum += *it;
        res += num;
    }

    sort(all(res));
    cout << res << "\n";
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