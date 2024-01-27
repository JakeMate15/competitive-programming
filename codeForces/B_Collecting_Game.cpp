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

struct info {
    int pos, res;
    ll val, vv;
};

void sol() {
    int n;
    cin >> n;

    vector<info> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i].pos = i;
        cin >> a[i].val;
        a[i].vv = a[i].val;
    }

    sort(a.begin() + 1, a.end(), [] (info a, info b) {
        return a.val < b.val;
    });

    for (int i = 1; i <= n; i++) {
        a[i].val += a[i - 1].val;
    }

    a[n].res = n - 1;
    for (int i = n - 1; i >= 1; i--) {
        a[i].res = (a[i].val >= a[i + 1].vv ? a[i + 1].res : i - 1);
    }

    sort(all(a), [] (info a, info b) {
        return a.pos < b.pos;
    }); 

    for (int i = 1; i <= n; i++) {
        cout << a[i].res << " \n"[i == n];
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