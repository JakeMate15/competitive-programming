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
    int n, m;
    cin >> n >> m;
 
    vector<ii> seg(m);
    for(auto &[l, r]: seg){
        cin >> l >> r;
    }
 
    int q;
    cin >> q;
    vi queries(q);
    for(int &x: queries) {
        cin >> x;
    }
 
    int l = -1, r = q, mid;
    while(l + 1 < r){
        mid = (r + l) / 2;
        // mid = min(q - 1, mid);
        // cerr << mid << " " << q << "\n";
        assert(mid < q);
 
        vi a(n + 1);
        for(int i = 0; i <= mid; i++) {
            a[queries[i]] = 1;
        }
 
        for(int i = 1; i <= n; i++) {
            a[i] += a[i - 1];
        }
 
        bool ok = false;
        for(auto [ll, rr]: seg){
            if( (rr - ll + 1) / 2 < a[rr] - a[ll - 1]) {
                ok = true;
                break;
            }
        }
 
        if(ok)  r = mid;
        else    l = mid;
 
    }
 
    cout << (r == q ? -1 : r + 1) << "\n";
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