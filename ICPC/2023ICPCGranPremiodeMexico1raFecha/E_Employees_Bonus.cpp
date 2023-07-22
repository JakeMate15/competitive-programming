#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,int> pvi;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(ll (i)=0; i<n; i++)
#define forr(i,a,n) for(ll i=(a); i<n; i++)
#define fore(i,a,n) for(ll i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define debug(a)    cout << a << "\n"

const int N = 1e5+10;
vector<int> arbol[N];
int meta[N+1];
vector<ll> metaE(1,0);
int eulerT[N+1];
int eIn[N+1];
int eFin[N+1];
int alcanzado[N+1];
int tamS[N];
int eulerCont = 1;

template<typename T>
struct SegmentTreeLazy{
	int N,h;
	vector<T> d;
	vector<pvi> ST;
    
	pvi merge(pvi a, pvi b){
	    if(a.first < b.first)   return a;
		else                    return b;
	}

	//Build from an array in O(n)
	SegmentTreeLazy(int n, vector<T> &a): N(n){
		ST.resize(N << 1);
		d.resize(N);
		h = 64 - __builtin_clzll(n);

		for(int i = 0; i < N; ++i)
			ST[N + i] = {a[i],i};
		for(int i = N - 1; i > 0; --i)
			ST[i] = merge(ST[i << 1] , ST[i << 1 | 1]);
	}
 
	void apply(int p, T value) {
		ST[p].first += value;
		if(p<N)	d[p]+= value;
	}
 
	// modify value of parents of p
	void build(int p){
		while(p>1){
			p >>= 1;
            pvi auxM = merge(ST[p << 1], ST[p << 1 | 1]);
			ST[p] = {auxM.first+d[p] , auxM.second}; 
		}
	}
 
	// propagate from root to p
	void push(int p){
		for (int s = h; s > 0; --s) {
			int i = p >> s;
			if (d[i] != 0) {
				apply(i << 1, d[i]);
				apply(i << 1 | 1, d[i]);
				d[i] = 0;
			}
		}
	}
 
	// add v to interval [l, r)
	void increment(int l, int r, T value) {	
		l += N, r += N;
		int l0 = l, r0 = r;
		for (; l < r; l >>= 1, r >>= 1) {
			if(l & 1) apply(l++, value);
			if(r & 1) apply(--r, value);
		}
		build(l0);
		build(r0 - 1);
	}
 
	// min on interval [l, r)
	pvi range_min(int l, int r) { 	
		l += N, r += N;
		push(l);
		push(r - 1);
		pvi res = {LLONG_MAX,0};
		for (; l < r; l >>= 1, r >>= 1) {
			if(l & 1)	res = merge(res, ST[l++]);
			if(r & 1)	res = merge(res, ST[--r]);
		}
		return res;
	}
    
};


void dfs(int u, int p) {
    tamS[u] = 1;
    eIn[u] = eulerCont;
    eulerT[eulerCont] = u;
    metaE.push_back(meta[u]);
    eulerCont++;

    for (int i = 0; i < arbol[u].size(); i++) {
        int v = arbol[u][i];
        if (v != p) {
            dfs(v, u);
            tamS[u] += tamS[v];
        }
    }

    eFin[u] = eulerCont - 1;
}


int main(){IO
    int n,q;cin>>n>>q;
    memset(alcanzado,-1,sizeof(alcanzado));

    forn(i,n)   cin>>meta[i+1];

    forn(i,n-1){
        int u,v;cin>>u>>v;
        arbol[u].push_back(v);
        arbol[v].push_back(u);
    }
    dfs(1,0);

    SegmentTreeLazy<ll> st((int)metaE.size(),metaE);
    int aux = 1;
    
    while(q--){
        //cout << "q: " <<aux<<"\n";
        int nodo,dinero;
        cin>>nodo>>dinero;

        int l,r;
        if(dinero%tamS[nodo]==0){
            l = eIn[nodo];
            r = eFin[nodo]+1;
            st.increment(l,r,-(dinero/tamS[nodo]));
        }
        else{
            l = eIn[nodo];
            r = eFin[nodo]+1;
            int sumaAux = -(dinero/tamS[nodo]);
            st.increment(l,r,sumaAux);
            st.increment(l,l+1,-dinero%tamS[nodo]);
        }

        pvi minimo = st.range_min(l,r);
        ll valor = minimo.first;
        int idx = minimo.second;
        
        
        while(valor<=0){
            //cout << "q: " << aux << " v: " << valor << " i: " << idx << "\n";
            alcanzado[eulerT[idx]] = aux;
            //st.set(idx,INT_MAX);
            st.increment(idx,idx+1,5e17+valor);
            minimo = st.range_min(l,r);
            valor = minimo.first;
            idx = minimo.second;
        }

        //cout << "acabado con " << aux << " v" << valor << endl;
        //cout << st.get(1,n+1).second << "\t" << st.get(1,n+1).first << endl;
        //cout << st.getPosInLevel(st.get(1,n+1).first,st.get(1,n+1).second) << endl;
        //for(auto x: st.tree)    cout << x.value << " ";
        //debug("");
        aux++;
    }


    fore(i,1,n){
        debug(alcanzado[i]);
    }

    return 0;
}