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

void sol(){
	int n;
	cin >> n;

	vector<pair<ll, int>> a(n + 1, {0, 0});
	for(int i = 1; i <= n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(all(a));

	vector<ll> pref(n + 2);
	for(int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1] + a[i].first; 
	}

	map<int, ll> res;
	for(int i = 1; i <= n; i++) {
		ll curr = 1;
		curr += (a[i].first + 1) * (i - 1) - pref[i - 1] + (1 - a[i].first) * (n - i) + pref[n] - pref[i];

		res[a[i].second] = curr; 
	}

	for(auto [i, r]: res) {
		deb(r);
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