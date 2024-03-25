#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

struct SegmentTree {
    int N;
    vector<vector<int>> tree;
    vector<int> lazy;

    SegmentTree(int n): N(n), tree(4*n, vector<int>(3, 0)), lazy(4*n, 0) {
        build(1, 0, N-1);
    }

    void build(int p, int l, int r) {
        if (l == r) { 
            tree[p][0] = 1; 
        } else {
            int mid = (l + r) / 2;
            build(p*2, l, mid);
            build(p*2+1, mid+1, r);
            tree[p][0] = tree[p*2][0] + tree[p*2+1][0];
        }
    }

    void push(int p, int l, int r) {
        int totalLazy = lazy[p] % 3;
        if (totalLazy > 0) {
            vector<int> temp(3);
            for (int i = 0; i < 3; ++i) {
                temp[(i + totalLazy) % 3] = tree[p][i];
            }
            tree[p] = temp;
            if (l != r) {
                lazy[p*2] += lazy[p];
                lazy[p*2+1] += lazy[p];
            }
            lazy[p] = 0;
        }
    }

    void update(int p, int l, int r, int ul, int ur, int addValue) {
        push(p, l, r); 
        if (ul > r || ur < l) return;
        if (l >= ul && r <= ur) { 
            lazy[p] += addValue;
            push(p, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(p*2, l, mid, ul, ur, addValue);
        update(p*2+1, mid+1, r, ul, ur, addValue);
        for (int i = 0; i < 3; ++i) {
            tree[p][i] = tree[p*2][i] + tree[p*2+1][i];
        }
    }

    void update(int l, int r, int value) {
        update(1, 0, N-1, l, r, value);
    }

    int query(int p, int l, int r, int ql, int qr) {
        push(p, l, r); 
        if (ql > r || qr < l) return 0;
        if (l >= ql && r <= qr) { 
            return tree[p][0]; 
        }
        int mid = (l + r) / 2;
        return query(p*2, l, mid, ql, qr) + query(p*2+1, mid+1, r, ql, qr);
    }

    int query(int l, int r) {
        return query(1, 0, N-1, l, r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    SegmentTree st(n);

    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;

        if (op == 0) {
            st.update(l, r, 1);
        }
        else {
            cout << st.query(l, r) << "\n";
        }
    }


    return 0;
}