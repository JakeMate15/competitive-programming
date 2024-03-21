#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll HASH = 257, MOD = 1e9 + 7;

#define neutro 0
struct nodo {
    ll valor = neutro;

    nodo(ll v) : valor(v) {}
    nodo() {}

    nodo operator+(const nodo &b) const {
        nodo res;
        res.valor = (valor + b.valor) % MOD;
        return res;
    }
};

template<typename T>
struct SegmentTree {
    int n;
    vector<nodo> st;

    SegmentTree(int n) : n(n) {
        st.resize(n << 1);
    }

    void build(vector<T> a) {
        for(int i = 0; i < n; i++)
            st[n + i] = nodo(a[i]);
        for(int i = n - 1; i > 0; i--)
            st[i] = st[i << 1] + st[i << 1 | 1];
    }

    void update(int i, T v) {
        for (st[i += n] = nodo(v); i > 1; i >>= 1)
            st[i >> 1] = st[i] + st[i ^ 1];
    }

    nodo query(int l, int r) {//[l, r)
        nodo resl, resr;
        for(l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if(l & 1) resl = resl + st[l++];
            if(r & 1) resr = st[--r] + resr;
        }
        return resl + resr;
    }
};

int N, Q;
ll powH[200005] = {1};

int main() {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        powH[i] = (powH[i - 1] * HASH) % MOD;
    }
    vector<ll> forwardInit(N), backwardInit(N);
    for (int i = 0; i < N; i++) {
        char c; cin >> c;
        forwardInit[i] = powH[i] * (ll)c % MOD;
        backwardInit[i] = powH[N - i - 1] * (ll)c % MOD;
    }

    SegmentTree<ll> forwardST(N), backwardST(N);
    forwardST.build(forwardInit);
    backwardST.build(backwardInit);

    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            int k; char c;
            cin >> k >> c; k--;
            forwardST.update(k, powH[k] * (ll)c % MOD);
            backwardST.update(k, powH[N - k - 1] * (ll)c % MOD);
        } else if (t == 2) {
            int l, r;
            cin >> l >> r; l--, r--;
            ll forward = forwardST.query(l, r).valor;
            forward = (forward * powH[N - 1 - r]) % MOD;
            ll backward = backwardST.query(l, r).valor;
            backward = (backward * powH[l]) % MOD;
            if (forward == backward)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}
