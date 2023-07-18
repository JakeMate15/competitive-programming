#include<bits/stdc++.h>
using namespace std;

#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(int (i)=0; i<n; i++)
#define forr(i,a,n) for(int i=(a); i<n; i++)
#define fore(i,a,n) for(int i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"
#define sz(a)       (int)a.size()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int mod = 1e9+7;

template<typename T>
struct SegmentTreeLazy{
	int N,h;
	vector<T> ST, d;

	//Build from an array in O(n)
	SegmentTreeLazy(int n, vector<T> &a): N(n){
		ST.resize(N << 1,1);
		d.resize(N,1);
		h = 64 - __builtin_clzll(n);

		for(int i = n - 1; i > 0; i--)
			ST[i] = ST[i << 1] + ST[i << 1 | 1];
	}

	void apply(int p, T value) {
		ST[p]   =   ST[p] * value % mod;
		if(p<N)	    d[p] = d[p] * value % mod;
	}

	// modify value of parents of p
	void build(int p){
		while(p>1){
			p >>= 1;
			ST[p] = (ST[p << 1] + ST[p << 1 | 1]) * d[p] % mod;
		}
	}

	// propagate from root to p
	void push(int p){
		for (int s = h; s > 0; --s) {
			int i = p >> s;
			if (d[i] != 0) {
				apply(i << 1, d[i]);
				apply(i << 1 | 1, d[i]);
				d[i] = 1;
			}
		}
	}

	// multiply v to interval [l, r)
	void multiply(int l, int r, T value) {	
		l += N, r += N;
		int l0 = l, r0 = r;
		for (; l < r; l >>= 1, r >>= 1) {
			if(l & 1) apply(l++, value);
			if(r & 1) apply(--r, value);
		}
		build(l0);
		build(r0 - 1);
	}

	// Sum on interval [l, r)
	T range_sum(int l, int r) { 	
		l += N, r += N;
		push(l);
		push(r - 1);
		T res = 0;
		for (; l < r; l >>= 1, r >>= 1) {
			if(l & 1)	res += ST[l++];
			if(res >= mod) res -= mod;
			if(r & 1)	res += ST[--r];
			if(res >= mod) res -= mod;
		}
		return res;
	}
    
};

int main(){IO
	int n,q;
	cin>>n>>q;

	vector<ll> a(n,0LL);
	SegmentTreeLazy<ll> st(n,a);

	while(q--){
		int op,l,r,v;
		cin>>op;

		if(op==1){
			cin>>l>>r>>v;

			st.multiply(l,r,v);
		}
		else{
			cin>>l>>r;
			debug(st.range_sum(l,r));
		}
	}
}