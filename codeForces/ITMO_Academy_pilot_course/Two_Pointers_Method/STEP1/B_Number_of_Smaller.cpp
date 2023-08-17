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
    int n,m;
    cin>>n>>m;

    vi a(n);
    vi b(m);

    for(int &x: a)  cin>>x;
    for(int &y: b)  cin>>y;

    for(int x: b){
        int l = -1, r = n+1, m;
        while(l+1<r){
            m = (l+r)/2;

            if(a[m]<x)  l = m;
            else        r = m;
        }

        if(r>n)    cout << 0 << " ";
        else       cout << r << " ";
    }
}

int main(){IO
	int t=1;
	//cin>>t;
	while(t--)  sol();
}