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

ll v, h;
const ld g = 9.8;
const ld eps = 1e-9, inf = numeric_limits<ld>::max(), pi = acos(-1);
bool le(ld a, ld b){return b-a > eps;} 

ld f(ld a) {
    ld ang = (1.0 * acos(-1) * a) / 180.0;

    ld vy = sin(ang) * v;
    ld vx = cos(ang) * v;
    ld t1 = (vy - sqrt(vy * vy + 2.0 * g * h)) / g;
    ld t2 = (vy + sqrt(vy * vy + 2.0 * g * h)) / g;

    ld t = max(t1, t2);
    
    return vx * t;
}

void sol() {
    if (v == -1 && h == -1) {
        return;
    }

    ld l = 0, r = 90;
    for (int i = 0; i <= 200; i++) {
        ld m1 = l + (r - l) / 3.0;
        ld m2 = r - (r - l) / 3.0;

        if (f(m1) < f(m2)) {
            l = m1;
        }
        else {
            r = m2;
        }
    }

    cout << fixed << setprecision(6) << f((l + r) / 2) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;

    while(cin >> v >> h) {
        sol();
    }

    return 0;
}