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
    int xA, yA, xB, yB, xC, yC;
    cin >> xA >> yA >> xB >> yB >> xC >> yC;

    int ans = 1;
    if (xA < xB && xA < xC) {
        ans += min(xB, xC) - xA;
    }
    if (xA > xB && xA > xC) {
        ans += xA - max(xB, xC);
    }
    if (yA < yB && yA < yC) {
        ans += min(yB, yC) - yA;
    }
    if (yA > yB && yA > yC) {
        ans += yA - max(yB, yC);
    }
    
    cout << ans << "\n";
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

/*

    if (xb > xa && xc > xa) {
        mn = min(xb - xa + 1, xc - xa + 1);
    }

    if (xb < xa && xc < xa) {
        mn = min(xa - xb + 1, xa - xc + 1);
    }

    res += (mn == INT_MAX ? 0 : mn);
    mn = INT_MAX;

    if (yb > ya && yc > ya) {
        mn = min(yb - ya + 1, yc - ya + 1);
    }

    if (yb < xa && yc < ya) {
        mn = min(ya - yb + 1, ya - yc + 1);
    }

*/