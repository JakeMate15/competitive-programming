#include<bits/stdc++.h>
using namespace std;

#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(int (i)=0; i<n; i++)
#define forr(i,a,n) for(int i=(a); i<n; i++)
#define fore(i,a,n) for(int i=(a); i<=n; i++)
#define all(v)		v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"
#define sz(a)       (int)a.size()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

void sol(){
	int n0,n1,n2;
	cin>>n0>>n1>>n2;

	if(n2>=1){
		if(n0>=1){
			n1--;
			forn(i,n0+1)		cout << 0;
		}
		forn(i,n2+1)			cout << 1;
		forn(i,n1/2)			cout << "01";
		if(n1&1)				cout << 0;
	}
	else{
		if(n0>=1){
			//n1--;
			forn(i,n0+1)		cout << 0;
			forn(i,n1/2)		cout << "10";
			if( n1&1 )			cout << 1;
		}
		else{
			if(n1&1){
				forn(i,n1/2+1)	cout << "10";
			}
			else{
				forn(i,n1/2)	cout << "10";
				cout << 1;
			}
		}
		
	}
	debug("");
}

int main(){IO
	int t=1;
	cin>>t;
	while(t--)  
		sol();
}