#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(ll (i)=0; i<n; i++)
#define forr(i,a,n) for(ll i=(a); i<n; i++)
#define fore(i,a,n) for(ll i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"

template<typename T>
struct SegmentTree{
	int N;
	vector<T> ST;
 
	//build from an array in O(n)
	SegmentTree(int N, vector<T> & arr): N(N){
		ST.resize(N << 1);
		for(int i = 0; i < N; ++i)
			ST[N + i] = arr[i];
		for(int i = N - 1; i > 0; --i)
			ST[i] = max(ST[i << 1] , ST[i << 1 | 1]);
	}
 
	//single element update in i
	void update(int i, T value){
		ST[i += N] = value; //update the element accordingly
		while(i >>= 1)
			ST[i] = max(ST[i << 1] , ST[i << 1 | 1]);
	}


    int atLeastX(int k) {
        int i = 0, s = N >> 1;
        for(int p = 2; p < 2 * N; p <<= 1, s >>= 1) {
            if(ST[p] < k)	p++, i += s;
        }
        if(ST[N + i] < k)	i = -1;
        return i;
    }
 
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

    void imp(){
        for(auto x: ST) cout << x << " ";
        //for(int i=0; i<N; i++) cout << ST[N+i] << " ";
        debug("");
    }
};

int main(){IO
    int n,q;cin>>n>>q;
    ll nT = 1;
    while(nT<n) nT<<=1;
    vector<int> a(nT,0);
    for(int i=0; i<n; i++)  cin>>a[i];

    SegmentTree<int> st(nT,a);
    
    while(q--){
        int op,k,valor,l;
        cin>>op;
        
        if(op==1){
            cin>>k>>valor;
            st.update(k,valor);
        }
        else{
            cin>>k>>l;
            debug(st.atLeastX(k,l,1,nT));
        }

    }

}