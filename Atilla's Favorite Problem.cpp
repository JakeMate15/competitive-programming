#include<bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
 
void sol(){
	int n;
	string s;
	
	cin >> n;
	cin >> s;
	
	sort(all(s));
	
	int tam = s[n-1];
	
	cout << tam-96 << endl;
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t =1;
	
	cin >> t;
	
	while(t--){
		sol();
	}
	
	return 0;
}