#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

void sol(){
	int n;
	cin >> n;

	vector<ll> a(n);
	ll res = LONG_LONG_MIN, sum = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		sum = max(a[i], sum + a[i]);
		res = max(res, sum);
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);


	int t = 1;
	//cin >> t;

	while(t--){
		sol();
	}

	return 0;
}