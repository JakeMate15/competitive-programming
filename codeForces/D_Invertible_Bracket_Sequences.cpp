#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

#define all(x)  x.begin(), x.end()
#define neutro  0
struct nodo {
    int valor = neutro;

    nodo(int v) : valor(v) {}
    nodo() {}

    nodo operator+(const nodo &b) {
        nodo res;

        res.valor = max(valor, b.valor);

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

void sol () {
    string s;
    cin >> s;

    int n = s.size(), mx = 0;
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = (s[i - 1] == '(' ? 1 : -1);
        pref[i] += pref[i - 1];
        mx = max(mx, pref[i]);
    }

    vector<vector<int>> cnt(mx + 1, vector<int>());
    for (int i = 0; i <= n; i++) {
        cnt[pref[i]].push_back(i);
    }

    int64_t ans = 0;
    SegmentTree<int> st(n + 1, pref);
    for (int i = 1; i <= n; i++) {
        int lo = i, hi = n + 1;
        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            if (2 * pref[i - 1] >= st.query(i, mid).valor) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        
        int iguales = upper_bound(all(cnt[pref[i - 1]]), lo) - lower_bound(all(cnt[pref[i - 1]]), i);
        ans += iguales;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}