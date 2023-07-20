#include<bits/stdc++.h>
using namespace std;

#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(int (i)=0; i<n; i++)
#define forr(i,a,n) for(int i=(a); i<n; i++)
#define fore(i,a,n) for(int i=(a); i<=n; i++)
#define all(v)	    v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"
#define sz(a)       (int)a.size()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

//Para procesar querys de tipo k-esimo es necesario crear un arbol binario perfector(llenar con 0's)
template<typename T>
struct SegmentTree{
	int N;
	vector<T> ST;
 
	//Creacion a partir de un arreglo O(n)
	SegmentTree(int N): N(N){
                ST.assign(2 * N, 0);
	}
 
	//Actualizacion de un elemento en la posicion i
	void update(int i, T value){
		ST[i += N] = value;     //Dato normal
		while(i >>= 1)
			ST[i] = ST[i << 1] + ST[i << 1 | 1];        //Dato normal  
	}

        int range_sum(int l, int r) {
                int res = 0;
                for(l += N, r += N; l < r; l >>= 1, r >>= 1) {
                        if(l & 1) res += ST[l++];
                        if(r & 1) res += ST[--r];
                }
                return res;
        }
};

void sol(){
        int n;
        cin>>n;

        vi a(n);
        for(auto &x: a) cin>>x;

        SegmentTree<int> st(n);

        for(auto x: a){
                st.update(x-1,1);
                cout << st.range_sum(x,n) << " ";
        }
}

int main(){IO
	int t=1;
	cin>>t;
	while(t--)  sol();
}