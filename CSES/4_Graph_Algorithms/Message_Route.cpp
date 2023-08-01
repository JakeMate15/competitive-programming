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

    vi g[n+1];
    forn(i,m){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    queue<int> q;
    vector<bool> visited(n+1,false);
    vi origen(n+1, 0);

    visited[1] = true;
    q.push(1);
    while (!q.empty()) {
        int s = q.front(); q.pop();

        for (auto u : g[s]) {
            if (visited[u]) continue;
            origen[u] = s; 
            visited[u] = true;
            q.push(u);
        }
    }

    if(!origen[n]){
        debug("IMPOSSIBLE");
        return;
    }

    vi res;
    int curr = n;
    res.push_back(n);

    while(curr!=1){
        curr = origen[curr];
        res.push_back(curr);
    }

    reverse(all(res));
    debug(sz(res));
    for(auto x: res)    cout << x << " ";
}

int main(){IO
	int t=1;
	//cin>>t;
	while(t--)  sol();
}