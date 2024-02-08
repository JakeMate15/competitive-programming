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
    ll cambios = neutro;
    int l, r;

    nodo(int i) : l(i), r(i) {}
    nodo() {}

    nodo operator+(const nodo &b) {
        nodo res;
        ll camb = 0;

        
        ii izq = {l, r}, der = {b.l, b.r};
        // cerr << izq.first << " " << izq.second << " , " << der.first << " " << der.second << "\n";
        if (izq > der) {
            camb++;
            swap(izq, der);
        }

        res.l = izq.first;
        res.r = der.second;
        
        if (izq.second + 1 == der.first) {
            res.cambios = cambios + b.cambios + camb;
        }
        else {
            res.cambios = INT_MIN;
        }

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
            cerr << x.l << " " << x.r << " \n";
        }
        cerr << "\n";
    }
};

void sol(){
    // cerr << "============\n";
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    SegmentTree<int> st(n, a);
    // st.imp();
    auto res = st.st[1].cambios;

    cout << max(res, -1LL) << "\n";
    // ll nc = LONG_LONG_MIN * 2;
    // cerr << nc << "\n";
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