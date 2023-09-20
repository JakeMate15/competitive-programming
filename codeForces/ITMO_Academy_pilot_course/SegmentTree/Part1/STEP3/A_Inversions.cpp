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

const int mx = 2e5+5;
template<typename T>
struct FenwickTree{
	int N;
	vector<T> bit;

	//build from array in O(n), indexed in 0
	FenwickTree(int N): N(N){
		bit.resize(N);
	}

	//single element increment
	void update(int pos, T value){
		while(pos < N){
			bit[pos] += value;
			pos |= pos + 1;
		}
	}

	//range query, [0, r]
	T query(int r){
		T res = 0;
		while(r >= 0){
			res += bit[r];
			r = (r & (r + 1)) - 1;
		}
		return res;
	}

	//range query, [l, r]
	T query(int l, int r){
		return query(r) - query(l - 1);
	}
};

void sol(){
	int n;
	cin>>n;

	vi a(n);
	for(auto &x: a){
		cin>>x;
	}

	FenwickTree<int> bit(mx);

	forn(i,n){
		deb(i-bit.query(a[i]));
		bit.update(a[i],1);
	}

}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);

	int t=1;
	//cin>>t;
	while(t--){
		sol();
	}

	return 0;
}