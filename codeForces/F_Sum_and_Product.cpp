#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl              cout << "\n";
#define u_map           gp_hash_table
#define uid(a, b)       uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multi_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

ll raiz(ll n) {
	ll lo = 0, hi = 5000000001;
	while (lo < hi) {
		ll x = (lo + hi) / 2;
		if (x * x >= n) {
			hi = x;
		} 
		else {
			lo = x + 1;
		}
	}
	return lo;
}

void sol(){
	int n;
	cin >> n;

	map<ll, int> mp;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mp[x]++;
	}

	int q;
	cin >> q;

	while(q--) {
		ll x, y;
		cin >> x >> y;

		ll d = 1LL * x * x - 4LL * y;
		if(d < 0) {
			deb(0);
			continue;
		}

		ll x1 = (x + raiz(d)) / 2;
		ll x2 = (x - raiz(d)) / 2;

		if(x1 + x2 != x || x1 * x2 != y) {
			deb(0);
		}
		else if(x1 == x2) {
			deb( (1LL * mp[x1] * (mp[x1] - 1)) / 2 );
		}
		else{
			deb(1LL * mp[x1] * mp[x2]);
		}

	}

	nl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	//cout << fixed << setprecision(10);

	int t=1;
	cin>>t;

	while(t--){
		sol();
	}

	return 0;
}