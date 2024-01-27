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
    int n;
    cin >> n;

    vector<ll> a(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<ll> l(n + 2), r(n + 2);
    l[2] = r[n - 1] = 1;
    for (int i = 2; i <= n; i++) {
        if (abs(a[i] - a[i + 1]) < abs(a[i] - a[i - 1])) {
            l[i + 1] = 1;
        }
        else {
            l[i + 1] = abs(a[i] - a[i + 1]);
        }

        l[i] += l[i - 1];
    }

    for (int i = n - 1; i >= 1; i--) {
        if (abs(a[i] - a[i + 1]) > abs(a[i] - a[i - 1])) {
            r[i - 1] = 1; 
        }
        else {
            r[i - 1] = abs(a[i] - a[i - 1]);
        }

        r[i] += r[i + 1];
    }

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;

        if (a < b) {
            cout << abs(l[a] - l[b]) << "\n";
        }
        else {
            cout << r[b] - r[a] << "\n";
        }
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