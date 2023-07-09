#include<bits/stdc++.h>
using namespace std;

#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(int (i)=0; i<n; i++)
#define forr(i,a,n) for(int i=(a); i<n; i++)
#define fore(i,a,n) for(int i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"
#define sz(a)       (int)a.size()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

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
			ST[i] = ST[i << 1] ^ ST[i << 1 | 1];
	}

	//range query, [l, r]
	T query(int l, int r){
		T resl=0,resr=0;
		for(l += N, r += N; l <= r; l >>= 1, r >>= 1){
			if(l & 1)       resl = resl ^ ST[l++];
			if(!(r & 1))    resr = ST[r--] ^ resr;
		}
		return resl ^ resr;
	}
};

int main(){IO
    int n,q;cin>>n>>q;

    vector<int> a(n);
    for(int &x: a)  cin>>x;

    SegmentTree<int> qu(n,a);

    while(q--){
        int l,r;
        cin>>l>>r;
        l--;r--;
        debug(qu.query(l,r));
    }
}