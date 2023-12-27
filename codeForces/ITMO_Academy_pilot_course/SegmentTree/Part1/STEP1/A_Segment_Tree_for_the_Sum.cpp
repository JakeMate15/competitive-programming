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
};

nodo operator+(const nodo& a, const nodo &b) {
    return a.valor + b.valor;
}

template<typename T>
struct SegmentTree {
    int n;
    vector<nodo> st;

    SegmentTree(int n, vector<T> a) : n(n) {
        st.resize(n * 2);
        for(int i = 0; i < n; i++) 
            st[i] = nodo(a[i]);
        for(int i = n - 1; i > 0; i--)
            st[i] = st[i << 1] + st[i << 1 | 1];
    }

    void update(int i, T v) {
        nodo nvo(v);
        st[i += n] = nvo;
        while(i >>= 1) 
            st[i] = st[i << 1] + st[i << 1 | 1];
    }

    T query(int l, int r) {
        nodo resl(neutro), resr(neutro);
        for(l += n, r += n; l <= r; l >>= 1, r >>= 1) {
            if(l & 1)   resl = resl + st[l++];
            if(r & 1)   resr = st[--r] + resr;
        }
        return (resl + resr).valor;
    }

    void imp() {
        for(int i = 1; i < 2 * n; i++) {
            cerr << st[i].valor << " \n"[i == 2 * n];
        }
    }
};


void sol(){
    int n, q;
    cin >> n >> q;

    vector<ll> a(n);
    for(auto &x: a) {
        cin >> x;
    }

    SegmentTree<ll> st(n, a);
    st.imp();

    while(q--) {
        int op, l, r;
        if(op == 1) {
            st.update(l, r);
        }
        else {
            cout << st.query(l, r) << "\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}