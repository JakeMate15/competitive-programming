#include<bits/stdc++.h>
using namespace std;

#define forn(i,n)       for(int i=0; i<n; i++)
#define forr(i,a,n)     for(int i=a; i<n; i++)
#define fore(i,a,n)     for(int i=a; i<=n; i++)
#define fornd(i,n)      for(int i=n; i>=0; i--)
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define pb              push_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

struct nodo{
    int valor;
};

nodo creaNodo(int valor){
    nodo res;

    res.valor = valor;

    return res;
}

nodo merge(nodo a, nodo b) {
    nodo res;

    res.valor = a.valor & b.valor;

    return res;
}

struct SegmentTree{
	int N;
	vector<nodo> ST;
 
	SegmentTree(int N, vector<int> & arr): N(N){
		ST.resize(N << 1);
		for(int i = 0; i < N; ++i)
			ST[N + i] = creaNodo(arr[i]); //Dato compuesto
		for(int i = N - 1; i > 0; --i)
			ST[i] = merge(ST[i << 1] , ST[i << 1 | 1]); //Dato compuesto
	}
 
	int query(int l, int r){
		nodo resl = creaNodo(INT_MAX), resr = creaNodo(INT_MAX);
		for(l += N, r += N; l <= r; l >>= 1, r >>= 1){
			if(l & 1)       resl = merge(resl,ST[l++]); 
			if(!(r & 1))    resr = merge(ST[r--],resr); 
		}
		return merge(resl,resr).valor;
	}

};

void sol(){
    int n;
    cin >> n;

    vi a(n);
    for(auto &x: a) {
        cin >> x;
    }

    SegmentTree st(n,a);
    int q;
    cin >> q;

    while(q--){
        int l, k;
        cin >> l >> k;
        l--;

        int ll = -2, rr = n;
        while(ll + 1 < rr) {
            int m = (ll+rr)/2;

            if(st.query(l,m) >= k) ll = m;
            else    rr = m;
        }

        if(st.query(l,ll) == 2147483647) {
            deb(-1);
        }
        else{
            deb(ll+1); 
        }
    }

    debln("");
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int t=1;
    cin>>t;
    while(t--){
        sol();
    }

    return 0;
}