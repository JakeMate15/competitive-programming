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
    int n;char c;
    cin>>n>>c;

    string s;
    cin>>s;
    s+=s;

    if(c=='g'){
        debug(0);
        return;
    }

    int res=0,mx=1e9;

    for(int i=n*2-1; i>=0; i--){
        if(s[i]=='g')   mx = i;
        if(i<n && s[i] == c)    res = max(res,mx-i);
    }

    debug(res);
}

int main(){IO
	int t=1;
	cin>>t;
	while(t--)  sol();
}