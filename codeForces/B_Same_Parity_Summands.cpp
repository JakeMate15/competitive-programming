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
	int n,k;
    cin>>n>>k;

    int n1 =  n - (k - 1);
    if(n1 > 0 && n1 % 2 == 1){
        deb("YES");
        forn(i,k-1) debl(1);
        deb(n-(k-1));

        return;
    }

    int n2 = n - 2 * (k - 1);
    if(n2 > 0 && n2 % 2 == 0){
        deb("YES");
        forn(i,k-1) 
            debl(2);
        deb(n-(2*(k-1)));

        return;
    }

    deb("NO");

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