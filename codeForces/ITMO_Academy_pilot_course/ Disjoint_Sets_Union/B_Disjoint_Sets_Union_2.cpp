#include<bits/stdc++.h>
using namespace std;

#define forn(i,n)       for(int i=0; i<n; i++)
#define forr(i,a,n)     for(int i=a; i<n; i++)
#define fore(i,a,n)     for(int i=a; i<=n; i++)
#define fornd(i,n)      for(int i=n; i>=0; i--)
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define pb              push_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

struct UnionFind {
  int n;
  vector<int> dad, size, mn,mx;
 
  UnionFind(int N) : n(N), dad(N), size(N, 1), mx(N),mn(N) {
    while (N--){
        dad[N] = N;
        mx[N] = mn[N] = N+1;
    }
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
    mn[Rv] = min(mn[Rv],mn[Ru]);
    mx[Rv] = max(mx[Rv],mx[Ru]);
  }
  // 4
  // O(lg*(N))
  bool areConnected(int u, int v) {
    return root(u) == root(v);
  }
  // 4
  int getSize(int u) { return mx[root(u)]; }
 
  int numberOfSets() { return n; }
};

void sol(){
    int n,q;
    cin>>n>>q;

    UnionFind ds(n);

    while(q--){
        string op;
        int u,v;
        cin>>op;

        if(op == "union"){
            cin>>u>>v;
            u--;v--;
            ds.join(u,v);
        }
        else{
            cin>>u;
            debln( (ds.getSize(u)) );
        }

    }
    //ds.get(1);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int t=1;
    //cin>>t;
    while(t--){
        sol();
    }

    return 0;
}