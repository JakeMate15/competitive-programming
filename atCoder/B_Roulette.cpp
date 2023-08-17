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

    vector<pii> a[40];

    int x;
    forn(i,n){
        cin>>x;

        forn(j,x){
            int lec;
            cin>>lec;

            a[lec].emplace_back(x,i+1);
        }
    }

    int m;
    cin>>m;

    sort(all(a[m]));

    set<int> res;
    int ant,act;

    if(sz(a[m]))    ant = a[m][0].first;

    forn(i,sz(a[m])){
        if(a[m][i].first == ant)  res.insert(a[m][i].second);
    }

    debug(sz(res));
    for(auto x: res){
        cout << x << " ";
    }
}

int main(){IO
	int t=1;
	//cin>>t;
	while(t--)  sol();
}