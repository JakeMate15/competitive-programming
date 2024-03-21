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

#define neutro  0
struct nodo {
    ll valor = neutro;

    nodo(ll v) : valor(v) {}
    nodo() {}

    nodo operator+(const nodo &b) {
        nodo res;

        res.valor = valor + b.valor;

        return res;
    }
};

template<typename T>
struct SegmentTree {
    int n;
    vector<nodo> st;

    SegmentTree(int n, vector<T> a) : n(n) {
        st.resize(n << 1);
        for(int i = 0; i < n; i++)
            st[n + i] = nodo(a[i]);
        for(int i = n - 1; i > 0; i--)
            st[i] = st[i << 1] + st[i << 1 | 1];
    }

    void update(int i, T v) {
        for (st[i += n] = nodo(v); i >>= 1; )
            st[i] = st[i << 1] + st[i << 1 | 1];
    }

    nodo query(int l, int r) {//[l, r)
        nodo resl, resr;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1)   resl = resl + st[l++];
            if(r & 1)   resr = st[--r] + resr;
        }
        return resl + resr;
    }

    void imp() {
        for(auto x: st) {
            cerr << x.valor << " ";
        }
        cerr << "\n";
    }
};

void sol(int n) {
    vector<ll> a(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    SegmentTree<ll> st(n * 2, a);
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += (st.query(i, i + n + 1).valor >= 0);
    }

    cout << res << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    //cin >> t;

    while(cin >> t) {
        if (t == 0) break;
        sol(t);
    }

    return 0;
}