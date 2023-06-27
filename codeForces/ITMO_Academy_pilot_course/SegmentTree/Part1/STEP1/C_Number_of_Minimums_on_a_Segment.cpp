#include <bits/stdc++.h>
using namespace std;

#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef pair<ll,int> pll;

template<typename T>
struct SegmentTree{
	int N;
	vector<pll> ST;

    pll aux( pll a, pll b ){
        if(a.first < b.first)       return a;
        else if(a.first > b.first)  return b;
        else                        return {a.first, a.second+b.second};
    }

	//build from an array in O(n)
	SegmentTree(int N, vector<T> & arr): N(N){
		ST.resize(N << 1);
		for(int i = 0; i < N; ++i)
			ST[N + i] = {arr[i],1};
		for(int i = N - 1; i > 0; --i)
			ST[i] = aux(ST[i << 1], ST[i << 1 | 1]);
	}

	//single element update in i
	void update(int i, T value){
		ST[i += N] = {value,1}; //update the element accordingly
		while(i >>= 1)
			ST[i] = aux(ST[i << 1], ST[i << 1 | 1]);
	}

	//range query, [l, r]
	pll query(int l, int r){
		pll res = {LLONG_MAX,0};
		for(l += N, r += N; l <= r; l >>= 1, r >>= 1){
			if(l & 1) res = aux(ST[l++], res);
			if(!(r & 1)) res = aux(ST[r--], res);
		}
		return res;
	}
};

int main(){IO
    int n,q;cin>>n>>q;
    vector<long long> a(n);
    for(long long &x: a)  cin>>x;

    SegmentTree<long long> st(n,a);
    while(q--){
        int i,l,r;
        cin>>i>>l>>r;

        if(i==1)    st.update(l,r);
        else{
            pll res = st.query(l,r-1);
            cout << res.first << " " << res.second << "\n";
        }
    }

}