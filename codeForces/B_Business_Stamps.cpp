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

void sol(){
    int n,m;
    cin>>n>>m;

    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;
    r1--, c1--, r2--, c2--;

    vector a(n,vector<int>(m));
    forn(i,n){
        forn(j,m){
            cin>>a[i][j];
            a[i][j] = 1 << (a[i][j]-1);
        }
    }

    int ans = 10;
    forr(s,0,(1<<10)){
        if(__builtin_popcount(s)>=ans)    continue;
        vector vis(n,vector<int>(m));

        auto dfs = [&](auto dfs, int r, int c){
            if(vis[r][c])   return;
            vis[r][c] = 1;

            if (r && (s & a[r - 1][c])) dfs(dfs, r - 1, c);
            if (c && (s & a[r][c - 1])) dfs(dfs, r, c - 1);
            if (r + 1 < n && (s & a[r + 1][c])) dfs(dfs, r + 1, c);
            if (c + 1 < m && (s & a[r][c + 1])) dfs(dfs, r, c + 1);
        };

        if (s & a[r1][c1]) dfs(dfs, r1, c1);
        if (vis[r2][c2]) ans = __builtin_popcount(s);
    }

    debln(ans);
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