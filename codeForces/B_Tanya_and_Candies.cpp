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
	
	vector<int> a(n);
	
	int ePref = 0, oPref = 0, eSuf = 0, oSuf = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (i & 1) eSuf += a[i];
		else oSuf += a[i];
	}
	
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (i & 1) eSuf -= a[i];
		else oSuf -= a[i];
		if (ePref + oSuf == oPref + eSuf) {
			++ans;
		}
		if (i & 1) ePref += a[i];
		else oPref += a[i];
	}
	
	cout << ans << endl;
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