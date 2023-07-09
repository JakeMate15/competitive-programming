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
struct SQRT{
	int N, S;
	vector<T> A, B;

	SQRT(int N): N(N){
		this->S = sqrt(N + .0) + 1;
		A.assign(N, 0);
		B.assign(S, 0);
	}

	void build(vector<T> & arr){
		A = vector<ll>(arr.begin(), arr.end());
		for(int i = 0; i < N; ++i) B[i / S] += A[i];
	}

	//single element update
	void update(int pos, T value){
		int k = pos / S;
		A[pos] = value;
		T res = 0;
		for(int i = k * S, end = min(N, (k + 1) * S) - 1; i <= end; ++i) res += A[i];
		B[k] = res;
	}

	//range query, [l, r]
	T query(int l, int r){
		T res = 0;
		int c_l = l / S, c_r = r / S;
		if(c_l == c_r){
			for(int i = l; i <= r; ++i) res += A[i];
		}else{
			for(int i = l, end = (c_l + 1) * S - 1; i <= end; ++i) res += A[i];
			for(int i = c_l + 1; i <= c_r - 1; ++i) res += B[i];
			for(int i = c_r * S; i <= r; ++i) res += A[i];
		}
		return res;
	}
};

void sol(){
    
}

int main(){IO
    int n,q;cin>>n>>q;

    vector<ll> a(n);
    for(ll &x: a)  cin>>x;

    SQRT<ll> qu(n);
    qu.build(a);

    while(q--){
        int l,r;
        cin>>l>>r;
        l--;r--;
        debug(qu.query(l,r));
    }
}