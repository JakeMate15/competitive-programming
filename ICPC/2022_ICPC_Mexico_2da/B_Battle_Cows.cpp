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
    int n, k; 
    cin >> n >> k; 
    k--;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int x = find_if(a.begin(), a.end(), [&](int v) { return v > a[k]; }) - a.begin();
    vector<int> pos(n); 
    iota(pos.begin(), pos.end(), 0);
    int ans = 0;
    
    for (int i : {0, x}) {
        if (i == n) {
            continue;
        }
        swap(pos[i], pos[k]);
        vector<int> stt(n);
        for (int j = 1, u = pos[0]; j < n; j++) {
            int v = pos[j];
            u = (a[u] > a[v] ? u : v);
            stt[u]++;
        }
        swap(pos[i], pos[k]);
        ans = max(ans, stt[k]);
    }
    cout << ans << '\n';
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