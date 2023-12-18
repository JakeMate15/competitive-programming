#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

//build on O(n log n), queries in O(1) for any operation
template<typename T>
struct DisjointSparseTable{
	vector<vector<T>> left, right;
	int K, N;

	DisjointSparseTable(vector<T> & arr){
		N = arr.size();
		K = log2(N) + 2;
		left.assign(K + 1, vector<T>(N));
		right.assign(K + 1, vector<T>(N));
		for(int j = 0; (1 << j) <= N; ++j){
			int mask = (1 << j) - 1;
			T acum = 0; //neutral element of your operation
			for(int i = 0; i < N; ++i){
                acum = gcd(acum, arr[i]);
				// acum += arr[i]; //your operation
				left[j][i] = acum;
				if((i & mask) == mask) acum = 0; //neutral element of your operation
			}
			acum = 0; //neutral element of your operation
			for(int i = N-1; i >= 0; --i){
                acum = gcd(acum, arr[i]);
				// acum += arr[i]; //your operation
				right[j][i] = acum;
				if((i & mask) == 0) acum = 0; //neutral element of your operation
			}
		}
	}

	T query(int l, int r){
		if(l == r) return left[0][l];
		int i = 31 - __builtin_clz(l^r);
		return gcd(left[i][r], right[i][l]);
        // return left[i][r] + right[i][l]; //your operation
	}
};

void sol(){
    int n, q;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    DisjointSparseTable<int> st(a);
    map<int, int> aux;
    for(int i = 0; i < n; i++) {
        // cerr << "============\n";
        for(int j = 0; j < n - i; j++) {
            // cerr << j << " " << j + i << "\n";
            auto x = st.query   (j, j + i);
            aux[x]++;
        }
    }

    cin >> q;
    while(q--) {
        int x;
        cin >> x;
        cout << aux[x] << "\n";
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}