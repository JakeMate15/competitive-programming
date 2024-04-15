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

const int P = 239017, MOD_X = 1e9 + 7, MOD_Y = 1e9 + 9, N = 3e6 + 5;
// using H = unsigned long long;
struct H {
    int x, y;
    H() = default;
    H(int _x): x(_x), y(_x) {}
    H(int _x, int _y): x(_x), y(_y) {}
    H operator+(const H& h) const { return H(add(x, h.x, MOD_X), add(y, h.y, MOD_Y)); }
    H operator-(const H& h) const { return H(sub(x, h.x, MOD_X), sub(y, h.y, MOD_Y)); }
    H operator*(const H& h) const { return H(mul(x, h.x, MOD_X), mul(y, h.y, MOD_Y)); }
    bool operator==(const H& h) const { return x == h.x && y == h.y; }
    // bool operator!=(const H& h) const { return x != h.x || y != h.y; }
    bool operator<(const H& h) const {if (x == h.x) {return y < h.y; } return x < h.x; }

    static ll add(ll a, ll b, ll mod) {
        a += b;
        return a >= mod ? a - mod : a;
    }

    static ll sub(ll a, ll b, ll mod) {
        a -= b;
        return a < 0 ? a + mod : a;
    }

    static ll mul(ll a, ll b, ll mod) {
        return ((a * 1ll * b) % mod);
    }
};

H p[N], h[N];

// Query desde 0, [l, r)
H get(int l, int r) { 
    return h[r] - h[l] * p[r - l]; 
}

void init(const string& s) {
    int n = sz(s);
    p[0] = 1;
    for (int i = 0; i < n; i++)
        h[i + 1] = h[i] * P + s[i], p[i + 1] = p[i] * P;
}

void sol() {
    int n;
    string s;
    cin >> n >> s;

    init(s);
    int res = n;
    for (int i = 1; i <= n; i++) {
        if (n % i != 0) continue;

        map<H, int> idx, cnt;

        for (int j = 0; j < n; j += i) {
            auto h = get(j, j + i);

            idx[h] = j;
            cnt[h]++;
        }

        if (sz(idx) == 1) {
            res = min(res, i);
            continue;
        }

        if (sz(idx) > 2) {
            continue;
        }

        auto [h1, r1] = *cnt.begin();
        auto [h2, r2] = *next(cnt.begin());


        if (min(r1, r2) != 1) {
            continue;
        }
        
        string s1 = s.substr(idx[h1], i), s2 = s.substr(idx[h2], i);
        int difs = 0;
        for (int k = 0; k < sz(s1); k++) {
            if (s1[k] != s2[k]) {
                difs++;
            }
        }

        difs *= min(r1, r2);
        if (difs == 1) {
            res = min(res, i);
        }
    }

    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}