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

    vector<ll> a(n),pref(n),suf(n);
    forn(i,n){
        cin>>a[i];
        if(i)   pref[i] = a[i]+pref[i-1];
        else    pref[i] = a[i];
    }

    suf[n-1] = a[n-1];
    for(int i=n-2; i>=0; i--){
        suf[i] = suf[i+1] + a[i];
    }

    map<ll,pair<int,int>> aux;
    forn(i,n){
        if(!aux.count(pref[i]))     aux[pref[i]] = {-1,-1};
        if(!aux.count(suf[n-i-1]))  aux[suf[n-i-1]] = {-1,-1};

        aux[ pref[i] ].first = i;
        aux[ suf[n-i-1] ].second = n-i-1;
    }

    int res = 0;
    for(auto x: aux){
        int a = x.second.first;
        int b = x.second.second;
        
        if(a>=0 && b>=0 && a<b) res = max(res, a+1 + n-b );
    }

    deb(res);

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