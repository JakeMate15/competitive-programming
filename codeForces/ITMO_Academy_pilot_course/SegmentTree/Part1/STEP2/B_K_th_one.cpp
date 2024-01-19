#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

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
        for (st[i += n].valor ^= 1; i >>= 1; )
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

    int kth_one (int k) {
        int i = 0, s = n >> 1;
        for(int p = 2; p < 2 * n; p <<= 1, s >>= 1) {
            if(k < st[p].valor)   continue;
            k -= st[p++].valor;
            i += s;
        }
        return i;
    }

    void imp() {
        for(auto x: st) {
            cerr << x.valor << " ";
        }
        cerr << "\n";
    }
};

void sol(){
    int n, q;
    cin >> n >> q;

    int nn = 1;
    while(nn < n)
        nn <<= 1;

    vector<int> a(nn, 0);
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    SegmentTree<int> st(nn, a);
    
    while(q--) {
        int op, i;
        cin >> op >> i;

        if(op == 1) {
            st.update(i, i + 1);
        }
        else {
            cout << st.kth_one(i) << "\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}
