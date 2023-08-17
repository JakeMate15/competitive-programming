#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool f(int n, int m){
    if(n==m)    return true;
    if(n<m)     return false;

    int a = (n*2)/3;
    int b = n/3;
    if(a+b != n)    return false;

    return (f(a,m) | f(b,m));
}

void sol(){
	int n,m;
    cin>>n>>m;

    if( f(n,m) )    cout << "YES\n";
    else            cout << "NO\n";
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