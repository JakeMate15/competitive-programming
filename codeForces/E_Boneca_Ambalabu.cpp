#include <bits/stdc++.h>
using namespace std;
 
const int B = 32;
struct SegmentTreeLazy {
    int n, h;
    vector<array<int, B>> tree;
    vector<int> lazy;
    vector<int> len;
    SegmentTreeLazy(vector<int>& a) {
        n = a.size();
        h = 32 - __builtin_clz(n);
        tree.resize(2 * n);
        lazy.assign(n, 0);
        len.resize(2 * n);
        for (int i = 0; i < n; i++) {
            len[i + n] = 1;
            for (int j = 0; j < B; j++)
                tree[i + n][j] = (a[i] >> j) & 1;
        }
        for (int i = n - 1; i > 0; i--) {
            len[i] = len[i << 1] + len[i << 1 | 1];
            for (int j = 0; j < B; j++)
                tree[i][j] = tree[i << 1][j] + tree[i << 1 | 1][j];
        }
    }
    void apply(int pos, int val) {
        for (int j = 0; j < B; j++)
            if (val & (1 << j))
                tree[pos][j] = len[pos] - tree[pos][j];
        if (pos < n)
            lazy[pos] ^= val;
    }
    void push(int pos) {
        if (lazy[pos]) {
            apply(pos << 1, lazy[pos]);
            apply(pos << 1 | 1, lazy[pos]);
            lazy[pos] = 0;
        }
    }
    void pushAll(int pos) {
        for (int s = h; s > 0; s--)
            push(pos >> s);
    }
    void pull(int pos) {
        for (int j = 0; j < B; j++)
            tree[pos][j] = tree[pos << 1][j] + tree[pos << 1 | 1][j];
        if (lazy[pos])
            for (int j = 0; j < B; j++)
                if (lazy[pos] & (1 << j))
                    tree[pos][j] = len[pos] - tree[pos][j];
    }
    void update_range(int l, int r, int val) {
        l += n, r += n;
        int l0 = l, r0 = r;
        for (int s = h; s > 0; s--) {
            push(l0 >> s);
            push((r0 - 1) >> s);
        }
        while (l < r) {
            if (l & 1) {
                apply(l, val);
                l++;
            }
            if (r & 1) {
                r--;
                apply(r, val);
            }
            l >>= 1, r >>= 1;
        }
        for (int s = 1; s <= h; s++) {
            if (((l0 >> s) << s) != l0)
                pull(l0 >> s);
            if ((((r0 - 1) >> s) << s) != (r0 - 1))
                pull((r0 - 1) >> s);
        }
    }
    int64_t query_range(int l, int r) {
        l += n, r += n;
        for (int s = h; s > 0; s--) {
            push(l >> s);
            push((r - 1) >> s);
        }
        array<int, B> res = {0};
        while (l < r) {
            if (l & 1) {
                for (int j = 0; j < B; j++)
                    res[j] += tree[l][j];
                l++;
            }
            if (r & 1) {
                r--;
                for (int j = 0; j < B; j++)
                    res[j] += tree[r][j];
            }
            l >>= 1, r >>= 1;
        }
        int64_t ans = 0;
        for (int j = 0; j < B; j++)
            ans += (int64_t)res[j] * (1LL << j);
        return ans;
    }
    void update(int pos, int l, int r, int ql, int qr, int val) {
        update_range(ql, qr, val);
    }
    int64_t query(int pos, int l, int r, int ql, int qr) {
        return query_range(ql, qr);
    }
};
 
void sol() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;
    int64_t ans = 0;
    SegmentTreeLazy st(arr);
    for (int i = 0; i < n; i++) {
        st.update(1, 0, n, 0, n, arr[i]);
        ans = max(ans, st.query(1, 0, n, 0, n));
        st.update(1, 0, n, 0, n, arr[i]);
    }
    cout << ans << "\n";
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while (t--) {
        sol();
    }
    return 0;
}
