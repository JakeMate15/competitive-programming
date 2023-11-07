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

//Para procesar querys de tipo k-esimo es necesario crear un arbol binario perfector(llenar con 0's)
template<typename T>
struct SegmentTree{
	int N;
	vector<T> ST;
 
	//Creacion a partir de un arreglo O(n)
	SegmentTree(int N, vector<T> & arr): N(N){
		ST.resize(N << 1);
		for(int i = 0; i < N; ++i)
			ST[N + i] = arr[i];     //Dato normal
		for(int i = N - 1; i > 0; --i)
			ST[i] = ST[i << 1] + ST[i << 1 | 1];        //Dato normal
	}
 
	//Actualizacion de un elemento en la posicion i
	void update(int i, T value){
		ST[i += N] = value;     //Dato normal
		while(i >>= 1)
			ST[i] = ST[i << 1] + ST[i << 1 | 1];        //Dato normal  
	}
 
	//query en [l, r]
	T query(int l, int r){
		T res = 0;  //Dato normal
		for(l += N, r += N; l <= r; l >>= 1, r >>= 1){
			if(l & 1)       res += ST[l++]; //Dato normal
			if(!(r & 1))    res += ST[r--]; //Dato normal
		}
		return res;                 //Dato normal
	}

	//Para estas querys es necesario que el st tenga el tam de la siguiente potencia de 2
	//ll nT = 1;
	// while(nT<n) nT<<=1;
	//vector<int> a(nT,0);	

	//Encontrar k-esimo 1 en un st de 1's
	int Kth_One(int k) {
		int i = 0, s = N >> 1;
		for(int p = 2; p < 2 * N; p <<= 1, s >>= 1) {
			if(k < ST[p])	continue;
			k -= ST[p++];	i += s;
		}
		return i;
	}

	//i del primer elemento >= k en todo el arr
	int atLeastX(int k){
		int i = 0, s = N >> 1;
		for(int p = 2; p < 2 * N; p <<= 1, s >>= 1) {
			if(ST[p] < k)	p++, i += s;
		}
		if(ST[N + i] < k)	i = -1;
		return i;
	}

	//i del primer elemento >= k en [l,fin]
	//Uso atLeastX(k,l,1,nT)
	int atLeastX(int x, int l, int p, int s) {
		if(ST[p] < x or s <= l)	return -1;
		if((p << 1) >= 2 * N)
			return (ST[p] >= x) - 1;
		int i = atLeastX(x, l, p << 1, s >> 1);
		if(i != -1)	return i;
		i = atLeastX(x, l - (s >> 1), p << 1 | 1, s >> 1);
		if(i == -1)	return -1;
		return (s >> 1) + i;
	}
};

vector<vector<pair<int>>>

void sol(){
    
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