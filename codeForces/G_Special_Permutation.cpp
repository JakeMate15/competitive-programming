#include<bits/stdc++.h>
using namespace std;

#define forn(i,n)       for(int i=0; i<n; i++)
#define forr(i,a,n)     for(int i=a; i<n; i++)
#define fore(i,a,n)     for(int i=a; i<=n; i++)
#define fornd(i,n)      for(int i=n; i>=0; i--)
#define fored(i,n,a)    for(int i=n; i>=a; i--)
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

    if(n<=3){
        deb(-1);
        return;
    }

    if(n==4){
        deb("2 4 1 3");
        return;
    }

    if(n&1) for(int i=n-1; i>=2; i-=2)   debl(i);
    else    for(int i=n; i>=2; i-=2)     debl(i);
    debl(5);
    for(int i=1; i<=n; i+=2){
        if(i!=5)    
            debl(i);
    }
    deb("");
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