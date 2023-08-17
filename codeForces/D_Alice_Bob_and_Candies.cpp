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

	deque<int> dq;
	forn(i,n){
		int x;cin>>x;
		dq.push_back(x);
	}

	int tot=0,a=0,b=0;
	int ant=0,curr=0;

	while(sz(dq)){
		if(!sz(dq))	break;
		tot++;

		
		while(curr<=ant && sz(dq)){
			a+=dq.front();
			curr+=dq.front();
			dq.pop_front();
			
		}
		//cout << tot << " " << a << " " << b << "\n";

		ant = curr;
		curr = 0;
		if(!sz(dq))	break;
		tot++;

		while(curr<=ant && sz(dq)){
			b+=dq.back();
			curr+=dq.back();
			dq.pop_back();
			
		}

		ant = curr;
		curr = 0;

	}

	debl(tot);debl(a);deb(b);

	//cout << "\n\n";
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