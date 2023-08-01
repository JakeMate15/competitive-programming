#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef long long ll;
typedef vector<int> vi;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(lli (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"

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
			ST[i] = max(ST[i << 1] , ST[i << 1 | 1]);        //Dato normal
	}
 
	//Actualizacion de un elemento en la posicion i
	void update(int i, T value){
		ST[i += N] = value;     //Dato normal
		while(i >>= 1)
			ST[i] = max(ST[i << 1] , ST[i << 1 | 1]);       //Dato normal  
	}
 
	//query en [l, r]
	T query(int l, int r){
		T res = LONG_LONG_MIN;  //Dato normal
		for(l += N, r += N; l <= r; l >>= 1, r >>= 1){
			if(l & 1)       res = max(ST[l++],res); //Dato normal
			if(!(r & 1))    res = max(ST[r--],res); //Dato normal
		}
		return res;           
	}
};

void sol(){
        int n; 
        cin >> n;
        vector<ll> d(n), v(n), t(n);
	
        map<ll, int> aux;
        for (int i = 0; i < n; i++) {
                cin >> d[i] >> v[i] >> t[i];
                t[i] = d[i] - t[i];
                aux[d[i]] = aux[t[i]] = 0;
        }
	
        int cnt = 0;
        for (auto &x : aux)
                x.second = cnt++;

        vector<ll> s(n * 2);
        SegmentTree st(s.size(),s);
        for (int i = 0; i < n; i++) {
                s[i] = v[i] + st.query(aux[t[i]], aux[d[i]]);
                st.update(aux[d[i]], s[i]);
        }
        cout << *max_element(s.begin(), s.end()) << endl;
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}