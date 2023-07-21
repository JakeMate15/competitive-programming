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
    int n;cin>>n;

    vector<pair<int,int>> a(n);
    forn(i,n){
        int x,y;
        cin>>x>>y;

        a[i].first = x;
        a[i].second = y;
    }


    int res = 1,mx = -1,curr=-1;;
    forn(i,n){
        if(a[i].second>=mx && a[i].first<=10){
            res = i+1;
            mx = a[i].second;
        }
    }

    debug(res);
}

int main(){IO
	int t=1;
	cin>>t;
	while(t--)  sol();
}