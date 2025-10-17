#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()

#define neutro -1
struct nodo {
    int64_t valor = neutro;
    nodo(int64_t v) : valor(v) {}
    nodo() {}
    nodo operator+(const nodo &b) const {
        nodo res;
        res.valor = max(valor, b.valor);
        return res;
    }
};

template<typename T>
struct SegmentTree {
    int n, N;
    vector<nodo> st;

    SegmentTree(int _n, const vector<T>& a) : n(_n) {
        N = 1;
        while (N < n) 
            N <<= 1;
        st.assign(2 * N, nodo());
        for (int i = 0; i < n; i++) 
            st[N + i] = nodo(a[i]);
        for (int i = N - 1; i > 0; i--) 
            st[i] = st[i << 1] + st[i << 1 | 1];
    }

    void update(int i, T v) {
        for (st[i += N] = nodo(v); i >>= 1; )
            st[i] = st[i << 1] + st[i << 1 | 1];
    }

    nodo query(int l, int r) { //[l, r)
        nodo resl, resr;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resl = resl + st[l++];
            if (r & 1) resr = st[--r] + resr;
        }
        return resl + resr;
    }

    int firstIdx(int pos, T v) {
        if (query(0, pos + 1).valor < v) return -1;
        return find(1, 0, N - 1, pos, v);
    }

    int find(int node, int l, int r, int pos, T v) {
        if (l > pos || st[node].valor < v) return -1;
        if (l == r) return l;
        int m = (l + r) >> 1;
        int res = find(node << 1, l, m, pos, v);
        if (res != -1) return res;
        return find(node << 1 | 1, m + 1, r, pos, v);
    }
};

void sol () {
    int n, k;
    cin >> n >> k;

    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    sort(all(a), [](auto &A, auto &B){ 
        return A[0] < B[0]; 
    });

    vector<int> L(n), R(n);
    for (int i = 0; i < n; i++) {
        L[i] = a[i][0];
        R[i] = a[i][1];
    }

    SegmentTree<int> st(n, R);
    queue<int> q;
    q.push(k);
    int ans = k;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        while (true) {
            int pos = upper_bound(all(L), x) - L.begin() - 1;
            if (pos < 0) break;
            int idx = st.firstIdx(pos, x);
            if (idx < 0) break;
            int nx = a[idx][2];
            ans = max(ans, nx);
            st.update(idx, neutro);
            q.push(nx);
        }
    }
    cout << ans << "\n";
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