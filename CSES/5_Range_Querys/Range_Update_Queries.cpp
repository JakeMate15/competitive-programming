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
struct SegmentTreeLazy{
	int N;
	vector<T> ST;
 
	//build from an array in O(n)
	SegmentTree(int N, vector<T> & arr): N(N){
		ST.resize(N << 1,0);
        /*
		for(int i = 0; i < N; ++i)
			ST[N + i] = arr[i];
		for(int i = N - 1; i > 0; --i)
			ST[i] = ST[i << 1] + ST[i << 1 | 1];
        */
	}
 
	void update(int l, int r, T value){
		for (l += N, r += N; l < r; l >>= 1, r >>= 1){
			if (l&1)     ST[l++] += value;
			if (r & 1)   ST[--r] += value;
		}
	}
 
	//Get element at i
	T query(int p){
		T res = 0;
		for (p += N; p > 0; p >>= 1) res += ST[p];
		return res;
	}
 
    void imp(){
        for(auto x: ST) cout << x << " ";
        debug("");
    }
};
 
void sol(){
    int n,q;
    cin>>n>>q;
 
    vector<ll> a(n);
    for(ll &x: a)  cin>>x;
    SegmentTree<ll> st(n,a);
    //st.imp();
 
    while(q--){
        int op;
        cin>>op;
 
        if(op==1){
            int l,r;
            ll v;
            cin>>l>>r>>v;
            l--;
 
            st.update(l,r,v);
            //st.imp();
        }
        else{
            int i;cin>>i;
            i--;
            //debug("");
            debug(st.query(i)+a[i]);
        }
    }
}
 
int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}