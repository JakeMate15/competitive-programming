#include<bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

typedef long long int lli;
typedef vector<int> vi;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(lli (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)
#define all(v)	    v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO	    cout << "NO\n"
#define debu(a)   cout << a << "\n"

const int mx = 3e5+5;
vi g[mx];
vector<lli> tam;
vector<bool> vis;

bool dfs (int u, int v){
	if(v==u)
		return 1;

	bool bandera = 0;
	tam[u] = 1;
	vis[u] = 1;

	for(auto w: g[u]){
		if(vis[w])
			continue;
		if(dfs(w,v)){
			bandera=1;
			continue;
		}
		tam[u]+=tam[w];
	}
	return bandera;
}

void sol(){
	int n,x,y;
	
	cin >> n >> x >> y;
	tam.resize(n+1);
	vis.resize(n+1);
	fore(i,1,n) {
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}


	dfs(x, y);
	lli d = tam[x];

	debug(tam);


	vis.assign(mx,false);
	
	dfs(y, x);
	lli e = tam[y];

	debug(tam);

	lli ans = lli(n) * (n - 1) - d * e;
	debu(ans);

}

int main(){IO
	int t=1;
	//cin>>t;
	while(t--)  sol();
}