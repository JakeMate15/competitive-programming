#include <bits/stdc++.h>
using namespace std;

#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

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
			ST[i] = min(ST[i << 1] , ST[i << 1 | 1]);
	}

	//single element update in i
	void update(int i, T value){
		ST[i += N] = value; //update the element accordingly
		while(i >>= 1)
			ST[i] = min(ST[i << 1] , ST[i << 1 | 1]);
	}

	//single element update in [l, r]
	void update(int l, int r, T value){
		l += N, r += N;
		for(int i = l; i <= r; ++i)
			ST[i] = value;
		l >>= 1, r >>= 1;
		while(l >= 1){
			for(int i = r; i >= l; --i)
				ST[i] = min(ST[i << 1] , ST[i << 1 | 1]);
			l >>= 1, r >>= 1;
		}
	}

	//range query, [l, r]
	T query(int l, int r){
		T res = LLONG_MAX;
		for(l += N, r += N; l <= r; l >>= 1, r >>= 1){
			if(l & 1) res = min( ST[l++], res);
			if(!(r & 1)) res = min(ST[r--],res);
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
        else        cout << st.query(l,r-1) << "\n";
    }

}