#include<bits/stdc++.h>
using namespace std;
 
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";
 
typedef long long ll;
typedef long double ld;
 
const int mod = 1e9 + 7;
const int MX = 2e5 + 5;
 
struct SegmentTree{
	int N;
	vector<ll> ST;
 
    SegmentTree() {}
 
	SegmentTree(int N, vector<int> & arr): N(N){
		ST.resize(N << 1);
		for(int i = 0; i < N; ++i)
			ST[N + i] = arr[i];    
		for(int i = N - 1; i > 0; --i)
			ST[i] = ST[i << 1] + ST[i << 1 | 1];
	}
 
    void build(int n, vector<int> &a) {
        N = n;
		ST.resize(N << 1);
		for(int i = 0; i < N; ++i)
			ST[N + i] = a[i];    
		for(int i = N - 1; i > 0; --i)
			ST[i] = ST[i << 1] + ST[i << 1 | 1];
    }
 
	void update(int i, ll value){
		ST[i += N] = value;
		while(i >>= 1)
			ST[i] = ST[i << 1] + ST[i << 1 | 1];
	}
 
	//query en [l, r]
	ll query(int l, int r){
		ll res = 0;  
		for(l += N, r += N; l <= r; l >>= 1, r >>= 1){
			if(l & 1)       res += ST[l++]; 
			if(!(r & 1))    res += ST[r--]; 
		}
		return res;                 
	}
 
    void imp() {
		for(int i = 0; i < N; ++i)
			cerr << ST[N + i] << " "; 
        cerr << "\n";
    }
};
 
 
struct HLD {
    int n;
    vector<int> siz, top, dep, parent, in, out, seq, valor;
    vector<vector<int>> adj;
    SegmentTree st;
    int cur;
    
    HLD() {}
    HLD(int n) {
        init(n);
    }
    void init(int n) {
        this->n = n;
        siz.resize(n);
        top.resize(n);
        dep.resize(n);
        parent.resize(n);
        in.resize(n);
        out.resize(n);
        seq.resize(n);
        valor.resize(n);
        cur = 0;
        adj.assign(n, {});
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void work(vector<int> v, int root = 0) {
        top[root] = root;
        dep[root] = 0;
        parent[root] = -1;
        dfs1(root);
        dfs2(root);
        for(int i = 0; i < n; i++) {
            valor[i] = v[seq[i]];
        }
        st.build(sz(v), valor);
    }
    void dfs1(int u) {
        if (parent[u] != -1) {
            adj[u].erase(find(adj[u].begin(), adj[u].end(), parent[u]));
        }
        
        siz[u] = 1;
        for (auto &v : adj[u]) {
            parent[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[adj[u][0]]) {
                swap(v, adj[u][0]);
            }
        }
    }
    void dfs2(int u) {
        in[u] = cur++;
        seq[in[u]] = u;
        for (auto v : adj[u]) {
            top[v] = v == adj[u][0] ? top[u] : v;
            dfs2(v);
        }
        out[u] = cur;
    }
 
    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                u = parent[top[u]];
            } else {
                v = parent[top[v]];
            }
        }
        return dep[u] < dep[v] ? u : v;
    }
    
    int dist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
    
    int jump(int u, int k) {
        if (dep[u] < k) {
            return -1;
        }
        
        int d = dep[u] - k;
        
        while (dep[top[u]] > d) {
            u = parent[top[u]];
        }
        
        return seq[in[u] - dep[u] + d];
    }
    
    bool isAncester(int u, int v) {
        return in[u] <= in[v] && in[v] < out[u];
    }
    
    int rootedParent(int u, int v) {
        swap(u, v);
        if (u == v) {
            return u;
        }
        if (!isAncester(u, v)) {
            return parent[u];
        }
        auto it = upper_bound(adj[u].begin(), adj[u].end(), v, [&](int x, int y) {
            return in[x] < in[y];
        }) - 1;
        return *it;
    }
    
    int rootedSize(int u, int v) {
        if (u == v) {
            return n;
        }
        if (!isAncester(v, u)) {
            return siz[v];
        }
        return n - siz[rootedParent(u, v)];
    }
    
    int rootedLca(int a, int b, int c) {
        return lca(a, b) ^ lca(b, c) ^ lca(c, a);
    }
 
    ll querySubArbol(int u) {
        return st.query(in[u], out[u] - 1);
    }
 
    void updateValor(int u, ll x) {
        valor[u] = x;
        st.update(in[u], x);
    }
 
    ll queryCamino(int u, int v) {
        ll res = 0;
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            // Consulta en [l, r]
            res += st.query(in[top[u]], in[u]);
            u = parent[top[u]];
        }
        if (dep[u] > dep[v]) swap(u, v);
        res += st.query(in[u], in[v]); // Incluye el LCA
        return res;
    }
};
 
void sol(){
    int n, q;
    cin >> n >> q;
 
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    HLD t(n);
 
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        t.addEdge(u, v);
        // cerr << u << " " << v << "\n";
    }
    t.work(a);
 
    while(q--) {
        int op, x, l;
        cin >> op;
 
        if(op == 1) {
            cin >> l >> x;
            t.updateValor(--l, x);
        }
        else {
            cin >> l;
            cout << t.queryCamino(0, --l) << "\n";
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