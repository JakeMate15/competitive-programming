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

void sol(){
	int n,x;
	cin>>n;

	deque<int> a;
	forn(i,n){
		cin>>x;
		a.push_back(x);
    }
    
	int ant=0,alice = 0,bob = 0, res=0, act = 0;
	while(sz(a)>=1){
        res++;
		act = 0;
        
		while( sz(a) && act<=ant){
 			alice+=a.front();
            act+=a.front();
			a.pop_front();
		}

		ant = act;

		if(sz(a)<1)  break;
        res++;
        act = 0;

		while(sz(a) && act<=ant){
			bob+=a.back();
            act+=a.back();
			a.pop_back();
		}
        ant = act;

	}

    cout << res << " " << alice << " " << bob << "\n";
}

int main(){IO
	int t=1;
	cin>>t;
	while(t--)  
		sol();
}