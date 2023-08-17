#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void sol(){
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n; i++)   cin>>a[i];

    int res = 0,curr=0;
    for(int i=0; i<n; i++){
        if(a[i]){
            res = max(res,curr);
            curr=0;
        }
        else{
            curr++;
        }
    }
    res = max(curr,res);
    cout << res << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t=1;
	cin>>t;
	while(t--){
		sol();
	}

	return 0;
}