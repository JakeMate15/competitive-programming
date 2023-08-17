#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void sol(){
	string s,c="codeforces";
    cin>>s;

    int res = 0;
    for(int i=0; i<10; i++){
        if(s[i]!=c[i])  res++;
    }
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