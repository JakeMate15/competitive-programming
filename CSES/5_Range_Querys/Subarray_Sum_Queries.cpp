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
	ll seg = neutro, sum = neutro, pref = neutro, suf = neutro;

	nodo(ll v) : seg(v), sum(v), pref(v), suf(v) {}
	nodo() {}

	nodo operator+(const nodo &b) {
		nodo res;

		res.seg = max({seg, b.seg, b.suf + pref});
		res.pref = max(b.pref, b.sum + pref);
		res.suf = max(suf, sum + b.suf);
		res.sum = sum + b.sum;

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
			cerr << x.seg << " ";
		}
		cerr << "\n";
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
    while(q--) {
        ll l, r;
        cin >> l >> r;

        st.update(--l, r);
        cout << st.query(0, n).seg << "\n";
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