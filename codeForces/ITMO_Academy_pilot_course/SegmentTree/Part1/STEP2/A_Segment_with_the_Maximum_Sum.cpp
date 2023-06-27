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

struct nodo{
    ll seg,pref,suf,sum;
};

nodo creaNodo(ll seg, ll pref, ll suf, ll sum){
    nodo res;

    res.seg = seg;
    res.pref = pref;
    res.suf = suf;
    res.sum = sum;

    return res;
}

nodo merge(nodo b, nodo a){
    nodo res;

    res.seg = max({a.seg,b.seg, a.suf+b.pref});
    res.pref = max(a.pref, a.sum+b.pref);
    res.suf = max(b.suf, b.sum+a.suf);
    res.sum = a.sum + b.sum;

    return res;
}

template<typename T>
struct SegmentTree{
	int N;
	vector<nodo> ST;

	//build from an array in O(n)
	SegmentTree(int N, vector<T> & arr): N(N){
		ST.resize(N << 1);
		for(int i = 0; i < N; ++i)
			ST[N + i] = creaNodo(arr[i],arr[i],arr[i],arr[i]);
		for(int i = N - 1; i > 0; --i)
			ST[i] = merge(ST[i << 1] , ST[i << 1 | 1]);
	}

	//single element update in i
	void update(int i, T value){
		ST[i += N] = creaNodo(value,value,value,value); //update the element accordingly
		while(i >>= 1)
			ST[i] = merge(ST[i << 1] , ST[i << 1 | 1]);
	}

	//range query, [l, r]
	T query(){
		return max(ST[1].seg,0LL);
	}
};

int main(){IO
    int n,q;cin>>n>>q;
    vector<int> a(n);
    for(int &x: a)  cin>>x;

    SegmentTree<int> st(n,a);
    debug(st.query());
    while(q--){
        int i,v;cin>>i>>v;
        st.update(i,v);
        debug(st.query());
    }

}