#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl              cout << "\n";
#define u_map           gp_hash_table
#define uid(a, b)       uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//template <typename T> using ordered_multi_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

bool cmp(multiset<ll> a, multiset<ll> b) {
	ll m1 = sz(a) == 1 ? *a.begin() : *next(a.begin());
	ll m2 = sz(b) == 1 ? *b.begin() : *next(b.begin());

	return m1 < m2;
}

void sol(){
    int m;
	cin >> m;

	vector<multiset<ll>> a(m);
	ll mn = LONG_LONG_MAX;

	for(int i = 0; i < m; i++) {
		int n;
		cin >> n;

		for(int j = 0; j < n; j++) {
			ll x;
			cin >> x;
			a[i].insert(x);
		}

		mn = min(mn, *a[i].begin());
	}

	sort(all(a), cmp);

	ll res = mn;
	for(int i = 1; i < m; i++) {
		res += sz(a[i]) == 1 ? *a[i].begin() : *next(a[i].begin());
	}

	cout << res << "\n";

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