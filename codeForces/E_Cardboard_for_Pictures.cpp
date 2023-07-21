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

ll ok(vector<ll> a, ll m){
    ll sum = 0;

    for(auto x: a){
        sum+= ((x+m)*(x+m));
    }

    return sum;

}

void sol(){
    int n;
    ll c;
    cin>>n>>c;

    vector<ll> a(n);
    forn(i,n)   cin>>a[i];

    ll l=0,r=1e9,m;
    while(l<=r){
        m = (l+r)/2;
        //cout << l << " " << r << " " << m << " " << endl;
        ll sum = ok(a,m);
        //cout << sum << " " << c << endl;
        if( sum == c){
            debug(m/2);
            return;
        }   
        else if(sum>c){
            r = m-1;
        }
        else{
            l = m+1;
        }
    }

    debug("\n\n");
}

int main(){IO
	int t=1;
	cin>>t;
	while(t--)  sol();
}