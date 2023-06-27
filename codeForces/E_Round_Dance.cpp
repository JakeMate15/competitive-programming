#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(lli (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"

struct UnionFind {
  int n;
  vector<int> dad, size;
 
  UnionFind(int N) : n(N), dad(N), size(N, 1) {
    while (N--) dad[N] = N;
  }
  // 4
  // O(lg*(N))
  int root(int u) {
    if (dad[u] == u) return u;
    return dad[u] = root(dad[u]);
  }
  // 8
  // O(1)
  void join(int u, int v) {
    int Ru = root(u), Rv = root(v);
    if (Ru == Rv) return;
    if (size[Ru] > size[Rv]) swap(Ru, Rv);
    --n, dad[Ru] = Rv;
    size[Rv] += size[Ru];
  }
  // 4
  // O(lg*(N))
  bool areConnected(int u, int v) {
    return root(u) == root(v);
  }
  // 4
  int getSize(int u) { return size[root(u)]; }
 
  int numberOfSets() { return n; }
};

void sol(){
    int n;cin>>n;
    UnionFind ds(n);
	set<int> g[n];

	forn(i,n){
		int l;cin>>l;
		l--;
		ds.join(i,l);
		g[i].insert(l);
		g[l].insert(i);
	}

	int componentes = ds.numberOfSets();
	vector<int> aux;
	forn(i,n){
		if(g[i].size() == 1){
			//cout << i << " ";
			aux.push_back(i);
		}
	}

	//debug("\n");
	forn(i,(int)aux.size()-1){
		ds.join(aux[i],aux[i+1]);
	}

	cout << ds.numberOfSets() << " " << componentes << "\n";
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}