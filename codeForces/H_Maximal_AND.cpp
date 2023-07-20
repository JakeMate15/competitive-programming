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

bool compare(int a, int b){
    return (32-__builtin_clz(a)) > (32-__builtin_clz(b));
}

void sol(){
	int n,k;
    cin>>n>>k;
    vi a(n);
    forn(i,n)   cin>>a[i];

    sort(all(a),compare);

    forn(i,n)
        cout << a[i] << " - " << (32-__builtin_clz(a[i])) << endl;

    debug("\n\n");
    

}

int main(){IO
	int t=1;
	cin>>t;
	while(t--)  
		sol();
}