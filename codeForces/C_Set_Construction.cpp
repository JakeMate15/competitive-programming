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
    int n;
    cin>>n;

    vi g[105];
    vi vis(105,0);
    map<int,int> rep,rep2;

    fore(i,1,n){
        string lec;
        cin>>lec;
        fore(j,1,n){
            if(lec[j-1]=='1'){
                g[j].pb(i);
                rep[j]++;
                rep2[j]++;
            }
        }
    }

    vi res[105];
    int inicio = (*prev(rep.end())).first;
    fore(i,1,inicio){
        res[inicio].pb(i);
    }

    auto dfs = [&](int u, int anterior ,auto && dfs) -> void{
        if(vis[u])  return;
        vis[u] = 1;

        deb(u);debln(anterior);
        if(u!=inicio){
            forr(i,0,sz(res[anterior])-1){
                res[u].pb(res[anterior][i]);
            }
            rep2[anterior]--;
        }

        for(auto v: g[u]){
            dfs(v,u,dfs);
        }
    };
    
    dfs(inicio,0,dfs);
    
    fore(i,1,n){
        deb(sz(res[i]));
        for(auto x: res[i]){
            deb(x);
        }
        debln("");
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int t=1;
    cin>>t;
    while(t--){
        sol();
    }

    return 0;
}