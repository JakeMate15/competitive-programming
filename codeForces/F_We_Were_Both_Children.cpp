#include<bits/stdc++.h>
using namespace std;

#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(int (i)=0; i<n; i++)
#define forr(i,a,n) for(int i=(a); i<n; i++)
#define fore(i,a,n) for(int i=(a); i<=n; i++)
#define all(v)	    v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"
#define sz(a)       (int)a.size()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

void sol(){
    int n;
    cin>>n;

    vi a(n+1,0);
    fore(i,0,n-1){
        int x; 
        cin>>x;
        if(x<=n)    
            a[x]++;
    }

    vi b(n+1,0);

    fore(i,1,n){
        for(int j=i; j<=n; j+=i){
            b[j]+=a[i];
        }
    }

    debug( (*max_element(all(b))) );
}

int main(){IO
	int t=1;
	cin>>t;
	while(t--)  sol();
}