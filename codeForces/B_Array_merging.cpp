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

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

void sol(){
    // cerr << "==========\n";
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    map<int, int> ra, rb;

    int ant = 0, cnt = 1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] != ant) {
            ra[ant] = max(ra[ant], cnt);
            cnt = 1;
            ant = a[i];
        }
        else {
            cnt++;
        }
    }
    ra[ant] = max(ra[ant], cnt);

    ant = 0, cnt = 1;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        if(b[i] != ant) {
            rb[ant] = max(rb[ant], cnt);
            cnt = 1;
            ant = b[i];
        }
        else {
            cnt++;
        }
    }
    rb[ant] = max(rb[ant], cnt);

    int res = 1;
    for(auto [v, r]: ra) {
        if(v == 0)  continue;
        res = max(res, r + rb[v]);
        // cerr << v << " " << r << "\n";
    }

    for(auto [v, r]: rb) {
        if(v == 0)  continue;
        res = max(res, r + ra[v]);
        // cerr << v << " " << r << "\n";
    }

    cnt = 0;
    int i = n - 1;
    while(i >= 0 && a[i] == a[n - 1]) {
        cnt++;
        i--;
    }
    i = 0;
    while(i < n && b[i] == a[n - 1]) {
        i++;
        cnt++;
    }
    res = max(res, cnt);

    i = n - 1;
    cnt = 0;
    while(i >= 0 && b[i] == b[n - 1]) {
        cnt++;
        i--;
    }
    i = 0;
    while(i < n && a[i] == b[n - 1]) {
        i++;
        cnt++;
    }
    res = max(res, cnt);

    cout << res << "\n";
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