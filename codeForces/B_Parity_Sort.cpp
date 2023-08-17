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

const int mod = 1e9+7;

void sol(){
    int n;cin>>n;
    int par = 0, impar = 0;

    vector<pii> a(n),b(n);
    
    fore(i,1,n){
        int x;
        cin>>x;

        a[i-1] = {x,x%2};
        b[i-1] = {x,x%2};
    }

    sort(all(a));

    forn(i,n){
        if(a[i].second != b[i].second){
            NO;
            return;
        }
    }

    YES;

    
}

int main(){IO
	int t=1;
	cin>>t;
	while(t--)  sol();
}