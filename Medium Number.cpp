#include<bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
int num[3];
 
 
void sol(){
	cin >> num[0];
	cin >> num[1];
	cin >> num[2];
	
	sort(num,num+3);
	
	cout << num[1] << endl;	
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