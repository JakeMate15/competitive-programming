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
	int n,q;
    cin>>n>>q;

    vi a(n);
    forn(i,n)   cin>>a[i];

    sort(all(a));
    reverse(all(a));
    fore(i,1,n-1)   a[i]+=a[i-1];

    while(q--){
        int x;
        cin>>x;

        auto it = lower_bound(all(a),x);

        if(it==a.end()) debug(-1);
        else            debug((it-a.begin())+1);
        
    }

}

int main(){IO
	int t=1;
	cin>>t;
	while(t--)  
		sol();
}