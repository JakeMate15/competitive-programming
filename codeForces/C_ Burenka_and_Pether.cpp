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

template<class T,
    class Cmp = less<T>>
struct RMQ {
    const Cmp cmp = Cmp();
    static constexpr unsigned B = 64;
    using u64 = unsigned long long;
    int n;
    vector<vector<T>> a;
    vector<T> pre, suf, ini;
    vector<u64> stk;
    RMQ() {}
    RMQ(const vector<T> &v) {
        init(v);
    }
    void init(const vector<T> &v) {
        n = v.size();
        pre = suf = ini = v;
        stk.resize(n);
        if (!n) {
            return;
        }
        const int M = (n - 1) / B + 1;
        const int lg = __lg(M);
        a.assign(lg + 1, vector<T>(M));
        for (int i = 0; i < M; i++) {
            a[0][i] = v[i * B];
            for (int j = 1; j < B && i * B + j < n; j++) {
                a[0][i] = min(a[0][i], v[i * B + j], cmp);
            }
        }
        for (int i = 1; i < n; i++) {
            if (i % B) {
                pre[i] = min(pre[i], pre[i - 1], cmp);
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (i % B != B - 1) {
                suf[i] = min(suf[i], suf[i + 1], cmp);
            }
        }
        for (int j = 0; j < lg; j++) {
            for (int i = 0; i + (2 << j) <= M; i++) {
                a[j + 1][i] = min(a[j][i], a[j][i + (1 << j)], cmp);
            }
        }
        for (int i = 0; i < M; i++) {
            const int l = i * B;
            const int r = min(1U * n, l + B);
            u64 s = 0;
            for (int j = l; j < r; j++) {
                while (s && cmp(v[j], v[__lg(s) + l])) {
                    s ^= 1ULL << __lg(s);
                }
                s |= 1ULL << (j - l);
                stk[j] = s;
            }
        }
    } 
    T operator()(int l, int r) {
        if (l / B != (r - 1) / B) {
            T ans = min(suf[l], pre[r - 1], cmp);
            l = l / B + 1;
            r = r / B;
            if (l < r) {
                int k = __lg(r - l);
                ans = min({ans, a[k][l], a[k][r - (1 << k)]}, cmp);
            }
            return ans;
        } else {
            int x = B * (l / B);
            return ini[__builtin_ctzll(stk[r - 1] >> (l - x)) + l];
        }
    }
};

constexpr int B = 700;
constexpr int N = 300000;

void sol() {
    int n, d, g;
    cin >> n >> d >> g;
    d = min(n, d);
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    
    RMQ rmq1(a);
    
    vector<int> b(n - d + 1);
    for (int i = 0; i < n - d + 1; i++) {
        b[i] = rmq1(i, i + d);
    }
    
    int q;
    cin >> q;
    
    vector<int> u(q), v(q), t(q);
    vector<int> ans(q);
    for (int i = 0; i < q; i++) {
        cin >> t[i] >> u[i] >> v[i];
        u[i]--, v[i]--;
    }
    
    RMQ<int, greater<int>> rmq2(b);
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        int lo = i, hi = n;
        while (lo < hi) {
            int x = (lo + hi + 1) / 2;
            if (x - i <= d || rmq2(i + 1, x - d + 1) < a[i]) {
                lo = x;
            } else {
                hi = x - 1;
            }
        }
        r[i] = lo;
    }
    
    vector<int> pq(q);
    iota(pq.begin(), pq.end(), 0);
    sort(pq.begin(), pq.end(),
        [&](int i, int j) {
            return a[v[i]] < a[v[j]];
        });
    
    int cur[N], mx[N], ansp[N] {};
    int up[N], vp[N];
    for (int i = 0; i < q; i++) {
        cur[i] = u[pq[i]];
        mx[i] = u[pq[i]];
        up[i] = u[pq[i]];
        vp[i] = v[pq[i]];
    }
    
    int pre[N], f[N], cost[N];
    
    for (int t = 0; t * B < n; t++) {
        int L = t * B, R = min(n, (t + 1) * B);
        
        vector<int> ab(R - L);
        for (int i = L; i < R; i++) {
            ab[i - L] = a[i];
        }
        sort(ab.begin(), ab.end());
        
        auto build = [&](int j) {
            int res = 0;
            for (int i = L; i < R; i++) {
                if (j > 0 && a[i] <= ab[j - 1]) {
                    res = max(res, r[i]);
                }
                pre[i] = res;
            }
            for (int i = R - 1; i >= L; i--) {
                if (pre[i] <= i) {
                    f[i] = -1;
                } else if (pre[i] >= R) {
                    f[i] = pre[i];
                    cost[i] = 1;
                } else {
                    f[i] = f[pre[i]];
                    cost[i] = 1 + cost[pre[i]];
                }
            }
        };
        
        int j = 0;
        build(0);
        for (int i = 0; i < q; i++) {
            if (cur[i] > vp[i]) {
                continue;
            }
            if (vp[i] < R || up[i] >= L) {
                for (int j = max(up[i], L); j <= min(vp[i], R - 1); j++) {
                    if (j > cur[i]) {
                        if (j > mx[i]) {
                            ansp[i] = 0;
                            cur[i] = vp[i] + 1;
                            break;
                        }
                        cur[i] = mx[i];
                        ansp[i]++;
                    }
                    if (a[j] <= a[vp[i]]) {
                        mx[i] = max(mx[i], r[j]);
                    }
                }
            } else {
                while (j < R - L && a[vp[i]] >= ab[j]) {
                    j++;
                    build(j);
                }
                if (cur[i] >= R - 1) {
                    mx[i] = max(mx[i], pre[R - 1]);
                } else {
                    if (cur[i] >= L) {
                        mx[i] = max(mx[i], pre[cur[i]]);
                    }
                    if (cur[i] + 1 > mx[i]) {
                        ansp[i] = 0;
                        cur[i] = vp[i] + 1;
                        continue;
                    }
                    cur[i] = mx[i];
                    ansp[i]++;
                    if (cur[i] < R) {
                        if (f[cur[i]] == -1) {
                            ansp[i] = 0;
                            cur[i] = vp[i] + 1;
                            continue;
                        }
                        ansp[i] += cost[cur[i]];
                        cur[i] = f[cur[i]];
                    }
                    mx[i] = max(mx[i], pre[R - 1]);
                }
            }
        }
    }
    
    for (int i = 0; i < q; i++) {
        ans[pq[i]] = ansp[i];
    }
    
    for (int i = 0; i < q; i++) {
        if (t[i] == 1) {
            ans[i] = min(ans[i], 1);
        }
        cout << ans[i] << "\n";
    }
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