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
    int n, cal;
    cin >> n >> cal;

    vector<int> a(n);
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }

    map<int, vector<pair<int, vector<int>>>> res;
    for (int i = 0; i < (1 << n); i++) {
        vector<int> curr;
        int sum = 0, calf;

        for (int j = 0; j <= 20; j++) {
            if (i & (1 << j)) {
                sum += a[j];
                curr.push_back(j + 1);
            }
        }
        
        calf = sum * 100 / total;
        if (calf >= cal) {
            res[sz(curr)].push_back({calf, {curr}});
        }
    }

    auto [tam, st] = *res.begin();
    cout << tam << " " << sz(st) << "\n";
    for (auto [c, v]: st) {
        cout << c;
        for (int i = 0; i < sz(v); i++) {
            cout << " " << v[i];
        }
        nl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}