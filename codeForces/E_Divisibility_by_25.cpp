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

/*
00
25
50
75
*/

void sol() {
    string n;
    cin >> n;

    map<char, int> rep;
    for (auto x: n) {
        rep[x]++;
    }

    if (rep['0'] < 2 && !(rep['2'] && rep['5']) && !(rep['5'] && rep['0']) && !(rep['7'] && rep['5'])) {
        cout << -1 << "\n";
        return;
    }

    ll nn = stoll(n);
    int res = 10;
    if (nn % 25 == 0) {
        res = 0;
    }

    reverse(all(n));
    cerr << n << "\n";
    if (rep['0'] >= 2) {
        int cnt = 0;
        int i = find(all(n), '0') - n.begin();

        for (; i >= 1; i--) {
            swap(n[i], n[i - 1]);
            cnt++;
        }

        i = find(n.begin() + 1, n.end(), '0') - n.begin();
        for (; i >= 2; i--) {
            swap(n[i], n[i - 1]);
            cnt++;
        }
        
        res = min(res, cnt);
    }

    if (rep['2'] && rep['5']) {
        int cnt = 0;
        int i = find(all(n), '5') - n.begin();

        for (; i >= 1; i--) {
            swap(n[i], n[i - 1]);
            cnt++;
        }

        i = find(n.begin() + 1, n.end(), '2') - n.begin();
        for (; i >= 2; i--) {
            swap(n[i], n[i - 1]);
            cnt++;
        }

        
        res = min(res, cnt);
    }

    if (rep['5'] && rep['0']) {
        int cnt = 0;
        int i = find(all(n), '0') - n.begin();

        for (; i >= 1; i--) {
            swap(n[i], n[i - 1]);
            cnt++;
        }

        i = find(n.begin() + 1, n.end(), '5') - n.begin();
        for (; i >= 2; i--) {
            swap(n[i], n[i - 1]);
            cnt++;
        }
        
        res = min(res, cnt);
    }

    if (rep['7'] && rep['5']) {
        int cnt = 0;
        int i = find(all(n), '5') - n.begin();

        for (; i >= 1; i--) {
            swap(n[i], n[i - 1]);
            cerr << n << "\n";
            cnt++;
        }

        cerr << n << "\n";
        i = find(n.begin() + 1, n.end(), '7') - n.begin();
        for (; i >= 2; i--) {
            swap(n[i], n[i - 1]);
            cnt++;
        }
        cerr << n << "\n";

        res = min(res, cnt);
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