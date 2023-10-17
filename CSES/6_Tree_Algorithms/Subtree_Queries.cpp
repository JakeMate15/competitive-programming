#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl              cout << "\n";
#define u_map           gp_hash_table
#define uid(a, b)       uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multi_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

vector<vector<int>> g;
vector<int> inE, outE, eT, tamS, aplanado;
vector<ll> c;
int cont = 0;

void eTour(int nodo, int padre) {
    tamS[nodo] = 1;
    inE[nodo] = cont;
    eT[cont] = nodo;
    aplanado.push_back(c[nodo]);
    cont++;

    for(auto u: g[nodo]) {
        if(u != padre) {
            eTour(u, nodo);
            tamS[nodo] += tamS[u]; 
        }
	}

    outE[nodo] = cont - 1;
}

struct SegmentTree{
	int N;
	vector<ll> ST;
 
	SegmentTree(int N, vector<int> & arr): N(N){
		ST.resize(N << 1);
		for(int i = 0; i < N; ++i)
			ST[N + i] = arr[i];    
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

void sol(){
    int n, q;
    cin >> n >> q;

    g.resize(n + 1);
    c.resize(n + 1);
    inE.resize(n + 1);
    outE.resize(n + 1);
    eT.resize(n + 1);
    tamS.resize(n + 1);

    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    eTour(1, 0);
    SegmentTree st(sz(aplanado), aplanado);

    while(q--) {
        ll op, s, x;
        cin >> op;

        if(op == 1) {
            cin >> s >> x;
            st.update(inE[s], x);
        }
        else{
            cin >> s;
            ll res = st.query(inE[s], outE[s]);
            cout << res << "\n";
        }

    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t=1;
    //cin>>t;

    while(t--){
        sol();
    }

    return 0;
}
