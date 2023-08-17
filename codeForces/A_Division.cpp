#include<bits/stdc++.h>
using namespace std;

#define forn(i,n)       for(int i=0; i<n; i++)
#define forr(i,a,n)     for(int i=a; i<n; i++)
#define fore(i,a,n)     for(int i=a; i<=n; i++)
#define fornd(i,n)      for(int i=n; i>=0; i--)
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define deb(a)          cout << a << "\n"
#define debl(a)         cout << a << " "
#define pb              push_back

typedef long long ll;
typedef vector<int> vi;
const int mod = 1e9+7;
const int mx = 1e9;

void sol(){
	int n;
    cin>>n;

    string s = "Division ";

    if(n<=1399) s+="4";
    else if(n<=1599)    s+="3";
    else if(n<=1899)    s+="2";
    else    s+="1";

    deb(s);
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