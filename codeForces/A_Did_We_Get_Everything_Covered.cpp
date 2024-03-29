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
    // cerr << "===========\n";
    int n, k, m;
    string s;
    cin >> n >> k >> m >> s;

    string res = "";
    vector<int> cnt(k, -1);
    for (int i = 0; i < m; i++) {
        char c = s[i];
        cnt[c - 'a'] = i;

        if (count(all(cnt), -1) == 0) {
            int letra = max_element(all(cnt)) - cnt.begin();
            res += (char) 'a' + letra;
            cnt = vector<int>(k, -1);
        }
    }

    if (sz(res) >= n) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";

        int p = min_element(all(cnt)) - cnt.begin();
        while (sz(res) < n) {
            res += (char) 'a' + p;
        }

        cout << res << "\n";
    }
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