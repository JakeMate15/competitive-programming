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
struct SparseTable{
	vector<vector<T>> ST;
	vector<int> logs;
	int K, N;

	SparseTable(vector<T> & arr){
		N = arr.size();
		K = log2(N) + 2;
		ST.assign(K + 1, vector<T>(N));
		logs.assign(N + 1, 0);
		for(int i = 2; i <= N; ++i)
			logs[i] = logs[i >> 1] + 1;
		for(int i = 0; i < N; ++i)
			ST[0][i] = arr[i];
		for(int j = 1; j <= K; ++j)
			for(int i = 0; i + (1 << j) <= N; ++i)
				ST[j][i] = (ST[j - 1][i] + ST[j - 1][i + (1 << (j - 1))]); //put the function accordingly
	}

	T sum(int l, int r){ //non-idempotent functions
		T ans = 0;
		for(int j = K; j >= 0; --j){
			if((1 << j) <= r - l + 1){
				ans += ST[j][l];
				l += 1 << j;
			}
		}
		return ans;
	}

	T minimal(int l, int r){ //idempotent functions
		int j = logs[r - l + 1];
		return min(ST[j][l], ST[j][r - (1 << j) + 1]);
	}
};

int main(){IO
    int n,q;cin>>n>>q;

    vector<ll> a(n);
    for(ll &x: a)  cin>>x;

    SparseTable<ll> qu(a);

    while(q--){
        int l,r;
        cin>>l>>r;
        l--;r--;
        debug(qu.sum(l,r));
    }
}