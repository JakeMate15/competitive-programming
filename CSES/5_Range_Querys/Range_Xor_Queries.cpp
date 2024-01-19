#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

struct bitwisePrefix {
	vector<vector<int>> pref;
	int bits = 31, n;
	
	bitwisePrefix(vector<int> a, int n) : n(n) {
		pref.resize(n + 5, vector<int> (bits + 3));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < bits; j++) {
				pref[i + 1][j] = pref[i][j] + ((a[i] & (1 << j)) ? 1 : 0);
			}
		}
	}
	
	// Query indexada en 1
	int query(int l, int r) {
		int res = 0;
		
		for(int i = 0; i < 31; i++) {
			int cntBits = pref[r][i] - pref[l - 1][i];
			if(cntBits & 1) {
				res |= (1 << i);
			}
		}
		
		return res;
	}
	
	void imprime() {
		for(int i = 1; i < n + 1; i++) {
			for(int j = 0; j < bits; j++) {
				cerr << pref[i][j] << " ";
			}
			cerr << "\n";
		}
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for(auto &x: a) {
		cin >> x;
	}

	bitwisePrefix st(a, n);
	while(q--) {
		int l, r;
		cin >> l >> r;

		cout << st.query(l, r) << "\n";
	}

	return 0;
}