#include<bits/stdc++.h>
using namespace std;
 
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
 
typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int mx = 2047276 + 5;

ll dp[mx];
ll pila[1505][1505];

void sol(){
    ll n = 1;
    for(int i = 1; i < 1500; i++){
        for(int j = 0; j < i; j++){
            pila[i - j][j + 1] = n * n + pila[i - j - 1][j + 1] + pila[i - j][j] - pila[i - j - 1][j];
            dp[n] = pila[i - j][j + 1];
            n++;
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    sol();
	int t=1;
	cin>>t;
	while(t--){
		int n; cin>>n;
        cout << dp[n] << "\n";
	}

	return 0;
}