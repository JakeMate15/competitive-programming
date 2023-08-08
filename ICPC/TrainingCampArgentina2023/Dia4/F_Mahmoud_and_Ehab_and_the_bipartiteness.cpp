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

const int mx = 1e5+5;
vi g[mx];
vi pa(mx);
bitset<mx> col;

void dfs (int u, int c) {
        for (int v : g[u]) {
                if (v != pa[u]) {
                        col[v] = 1 - c;
                        pa[v] = u;
                        dfs(v, 1-c);
                }
        }
}

void sol(){
        int n;
        cin>>n;

        int a,b;
        forn(i,n-1) {
                cin >> a >> b;
                g[a].push_back(b);
                g[b].push_back(a);
        }

        dfs(1, 0);

        lli res = 0;
        for (int i = 1; i <= n; i++) {
                if (!col[i]) {
                        res += col.count() - g[i].size();
                }
        }

        debug(res);

}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}

