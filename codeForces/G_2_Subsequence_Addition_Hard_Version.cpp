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
    int n;
    cin>>n;

    vi a(n);
    for(auto &x: a) cin>>x;
    sort(all(a));

    if(a[0]!=1){
        NO;
        return;
    }

    ll suma = 1;

    forr(i,1,n){
        if(suma<a[i]){
            NO;
            return;
        }
        suma+=a[i];
    }

    YES;

}

int main(){IO
	int t=1;
	cin>>t;
	while(t--)  sol();
}