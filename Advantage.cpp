#include<bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
 
 
void sol(){
	int n;
	
	cin >>n;
	
	int parts[n];
	int aux[n];
	
	int auxv;
	
	for(int i=0; i<n; i++){
		cin >> auxv;
		parts[i] = auxv;
		aux[i] = auxv;
		
	}
	
	sort(aux,aux+n);
	
	int Max = aux[n-1];
	int smax = aux[n-2];
	
	for(int i=0; i<n; i++){
		if(parts[i]!=Max){
			cout << parts[i]-Max << " ";
		}
		else{
			cout << parts[i]-smax << " ";
		}
	
		//cout << parts[i]-max << " ";
	}
	
	cout << endl;
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