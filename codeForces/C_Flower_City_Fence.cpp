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

 
template<typename T>
struct SegmentTreeLazy{
	int N,h;
	vector<T> ST, d;
 
	//Creacion a partir de un arreglo
	SegmentTreeLazy(int n, vector<T> &a): N(n){
		//En caso de inicializar en cero o algo similar, revisar que la construccion tenga su respectivo neutro mult y 1       
		ST.resize(N << 1);
		d.resize(N);
		h = 64 - __builtin_clzll(n);
 
		for(int i = 0; i < N; ++i)
			ST[N + i] = a[i];
		//Construir el st sobre la query que se necesita
		for(int i = N - 1; i > 0; --i)
			ST[i] = min(ST[i << 1] , ST[i << 1 | 1]);
	}

	//Modificar de acuerdo al tipo modificacion requerida, +,*,|,^,etc
	void apply(int p, T value) {
		ST[p] += value;
		if(p<N)	d[p]+= value;
	}
 
	// Modifica valores de los padres de p
	//Modificar de acuerdo al tipo modificacion requerida, +,*,|,^,etc y a la respectiva query
	void build(int p){
		while(p>1){
			p >>= 1;
			ST[p] = min(ST[p << 1], ST[p << 1 | 1]) + d[p];
			//ST[p] = (ST[p << 1] & ST[p << 1 | 1]) | d[p]; Ejemplos con bitwise
		}
	}
 
	// Propagacion desde la raiz a p
	void push(int p){
		for (int s = h; s > 0; --s) {
			int i = p >> s;
			if (d[i] != 0) {
				apply(i << 1, d[i]);
				apply(i << 1 | 1, d[i]);
				d[i] = 0;   //Tener cuidado si estoy haciendo multiplicaciones
			}
		}
	}
 
	// Sumar v a cada elemento en el intervalo [l, r)
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
 
	// Sum on interval [l, r)
	T range_sum(int l, int r) { 	
		l += N, r += N;
		push(l);
		push(r - 1);
		T res = 0;
		for (; l < r; l >>= 1, r >>= 1) {
			if(l & 1)	res += ST[l++];
			if(r & 1)	res += ST[--r];
		}
		return res;
	}
    
};

void sol(){
    int n;
    cin>>n;

    vector<ll> a(n);
    for(auto &x: a){
        cin>>x;
    }

    if(a[0]!=n){
        debln("NO");
        return;
    }

    vector<ll> aux(a[0],1);
    SegmentTreeLazy<ll> st(sz(aux),aux);

    forr(i,1,n){
        //deb(0);debln(a[i]);
        st.increment(0,a[i],1LL);
    }

    forn(i,n){
        ll aux = st.range_sum(i,i+1);
        if(aux != a[i]){
            debln("NO");
            return;
        }
    }

    debln("YES");

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    cin>>t;
    while(t--){
        sol();
    }

    return 0;
}