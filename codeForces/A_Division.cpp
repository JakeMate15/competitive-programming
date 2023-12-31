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

	cout << "Division ";
	if(n <= 1399)	cout << 4;
	else if(n <= 1599) cout << 3;
	else if(n <= 1899) cout << 2;
	else cout << 1;
	nl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	//cout << fixed << setprecision(10);

	int t = 1;
	cin >> t;

	while(t--){
		sol();
	}

	return 0;
}