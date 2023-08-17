#include<bits/stdc++.h>
using namespace std;

#define forn(i,n)       for(int i=0; i<n; i++)
#define forr(i,a,n)     for(int i=a; i<n; i++)
#define fore(i,a,n)     for(int i=a; i<=n; i++)
#define fornd(i,n)      for(int i=n; i>=0; i--)
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)      	cout << a << "\n"
#define deb(a)        	cout << a << " "
#define pb              push_back

typedef long long ll;
typedef vector<int> vi;
const int mod = 1e9+7;
const int mx = 1e9;

void sol(){
    ll n, total=0, ans=INT_MAX;
	cin >> n;
	ll arr[n];
	for(ll i = 0; i < n; i++) {
		cin >> arr[i];
		total += arr[i];
	}
	for(ll i = 0; i < 1<<n; i++) {
		ll s = 0;
		for(ll j = 0; j < n; j++) {
			if(i & 1<<j) s += arr[j];
		}
		ll curr = abs((total-s)-s);
		ans = min(ans, curr);
	}
	cout << ans;

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t=1;
	//cin>>t;
	while(t--){
		sol();
	}

	return 0;
}