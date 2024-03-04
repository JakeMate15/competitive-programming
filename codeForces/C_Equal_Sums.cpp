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
    int k;
    cin >> k;

    vector<vector<int>> a(k);
    vector<pair<ll, pair<int, int>>> aux;
    for (int i = 0; i < k; i++) {
        int t;
        cin >> t;
            
        ll sum = 0;
        for (int j = 0; j < t; j++) {
            int x;
            cin >> x;
            a[i].push_back(x);
            sum += x;
        }

        for (int j = 0; j < t; j++) {
            aux.emplace_back(sum - a[i][j], make_pair(i + 1, j + 1));
        }
    }

    sort(all(aux));
    for (int i = 0; i < sz(aux) - 1; i++) {
        auto [s1, p1] = aux[i];
        auto [st1, pos1] = p1;
        auto [s2, p2] = aux[i + 1];
        auto [st2, pos2] = p2;

        if (s1 == s2 && st1 != st2) {
            cout << "YES\n";
            cout << st1 << " " << pos1 << "\n";
            cout << st2 << " " << pos2 << "\n";
            return;
        }
    }

    cout << "NO\n";

    
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