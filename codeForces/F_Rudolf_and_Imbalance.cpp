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

int get(const ordered_set<int>& a) {
    int maxGap = 0;
    int prev = *a.begin();
    for(auto it = ++a.begin(); it != a.end(); ++it) {
        maxGap = max(maxGap, *it - prev);
        prev = *it;
    }
    return maxGap;
}

void sol() {
    int n, m, k;
    cin >> n >> m >> k;

    vi a(n), d(m), f(k);
    ordered_set<int> problems;

    for (int& ai : a) {
        cin >> ai;
        problems.insert(ai);
    }
    for (int& di : d) cin >> di;
    for (int& fi : f) cin >> fi;

    int initialGap = get(problems);
    int result = initialGap;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            int newComplexity = d[i] + f[j];
            if (problems.find(newComplexity) == problems.end()) { 
                problems.insert(newComplexity);
                result = min(result, get(problems));
                problems.erase(newComplexity);
            }
        }
    }

    cout << result << "\n";
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