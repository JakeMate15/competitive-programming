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
    int n,k;cin>>n>>k;
    vi a(n);

    forn(i,n)   cin>>a[i];
    sort(all(a));
    a.push_back(-59);

    int mx = 0,curr=1,ant=a[0];
    forr(i,1,n){
        if(abs(a[i]-ant<=k)){
            curr++;
            ant = a[i];
        }
        else{
            if(curr>=mx){
                mx = curr;
            }

            ant = a[i];
            curr = 1;
        }
    }

    mx = max(curr,mx);

    debug(n-mx);

}

int main(){IO
	int t=1;
	cin>>t;
	while(t--)  sol();
}