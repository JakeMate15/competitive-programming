#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multi_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define all(v)          v.begin(), v.end()
#define rall(v)         v.rbegin(), v.rend()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '"' << x << '"';}
void __print(const string &x) {cerr << '"' << x << '"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}

template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << '}';}

void _print() {cerr << "]\n";}

template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#define RAYA            cerr << "==========================\n";
#define raya            cerr << "--------------------------\n";
#else
#define debug(x...)
#define RAYA
#define raya
#endif

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;


struct nodo {
    int mn, mx;
    bool ordenado;

    nodo(int v) {
        mn = mx = v;
        ordenado = true;
    }
    nodo() {
        mn = INT_MAX;
        mx = INT_MIN;
        ordenado = true;
    }

    nodo operator+(const nodo &b) {
        nodo res;

        res.mn = min(mn, b.mn);
        res.mx = max(mx, b.mx);
        res.ordenado = ordenado && b.ordenado && mx <= b.mn;

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

    nodo query(int l, int r) { //[l, r)
        nodo resl, resr;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1)   resl = resl + st[l++];
            if(r & 1)   resr = st[--r] + resr;
        }
        return resl + resr;
    }
};

#define neutro  0
struct nodo2 {
    int valor = neutro;

    nodo2(int v) : valor(v) {}
    nodo2() {}

    nodo2 operator+(const nodo2 &b) {
        nodo2 res;

        res.valor = gcd(valor, b.valor);

        return res;
    }
};

template<typename T>
struct SegmentTree2 {
    int n;
    vector<nodo2> st;

    SegmentTree2(int n, vector<T> a) : n(n) {
        st.resize(n << 1);
        for(int i = 0; i < n; i++)
            st[n + i] = nodo2(a[i]);
        for(int i = n - 1; i > 0; i--)
            st[i] = st[i << 1] + st[i << 1 | 1];
    }

    void update(int i, T v) {
        for (st[i += n] = nodo2(v); i >>= 1; )
            st[i] = st[i << 1] + st[i << 1 | 1];
    }

    nodo2 query(int l, int r) {//[l, r)
        nodo2 resl, resr;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1)   resl = resl + st[l++];
            if(r & 1)   resr = st[--r] + resr;
        }
        return resl + resr;
    }
};

void sol() {
    // cout << "======================\n";
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a)
        cin >> x;

    vector<int> b;
    for (int i = 0; i < n - 1; i++) {
        b.push_back(gcd(a[i], a[i + 1]));
    }

    int m = sz(b);
    SegmentTree<int> st(m, b);
    SegmentTree2<int> st2(n, a);

    bool res = st.query(0, m).ordenado;
    for (int i = 0; i < n; i++) {
        int l = max(0, i - 1), r = min(i + 1, n - 1);
        int ant = a[i];
        st2.update(i, 0);
        int g = st2.query(l, r).valor;
        st2.update(i, ant);

        st.update(min(i, n - 1), g);
        res |= st.query(0, m - 1).ordenado;
        st.update(min(i, n - 1), b[min(i, n - 1)]);
    }

    cout << (res ? "YES" : "NO") << "\n";

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

// -Wall -Wextra -Wshadow -D_GLIBCXX_ASSERTIONS -DDEBUG -ggdb3 -fmax-errors=2