#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(lli (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"

vector<vector<pair<int,int>>> g;
int ans;

void dfs(int v, int p, int ct) {
    ans = max(ans, ct);
    for(auto &[u, i] : g[v]) {
        if (i == p) continue;
        if (i < p) dfs(u, i, ct + 1);
        else dfs(u, i, ct);
    }
}

void sol() {
    int n; cin >> n;
    g.clear();
    g.resize(n+5);
    forn(i, n - 1) {
        int u, v; cin >> u >> v;
        g[v].emplace_back(u, i);
        g[u].emplace_back(v, i);
    }
    ans = 1;
    dfs(1, -1, 1);
    debug(ans);
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}