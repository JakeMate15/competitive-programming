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
    int n,k;
    cin>>n>>k;

    vi a(n);
    for(int &x: a){
        cin>>x;
    }

    int x=0,y=0;
    bool cambio = false;
    forn(i,n){
        if(cambio){
            if(a[i] == a.back())    y++;
        }
        else{
            if(a[i]==a[0]){
                x++;
                if(x>=k)    cambio = true;
            }
            
        }
    }

    if( (a[0]==a.back() && x>=k) || (x>=k && y>=k)) YES;
    else    NO;


}

int main(){IO
	int t=1;
	cin>>t;
	while(t--)  sol();
}