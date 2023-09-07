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

const int mx = 1e5+5;
vi g[mx];
int v[mx];
struct query{
    int op,num,pos;
};
vector<query> q(mx);
vi dp;
int res[mx];

void dfs(int nodo, int padre){
    if(dp.back()<v[nodo]){
        dp.pb(v[nodo]);
        q[nodo].op = 1;
    }
    else{
        int i = lower_bound(all(dp),v[nodo])-dp.begin();
        q[nodo].op = 2,q[nodo].num = dp[i], q[nodo].pos = i;
        dp[i] = v[nodo];
    }

    res[nodo] = sz(dp)-1;
    
    for(auto u: g[nodo]){
        if(u!=padre){
            dfs(u,nodo);
        }
    }

    if(q[nodo].op==1){
        dp.pop_back();
    }
    else if(q[nodo].op == 2){
        dp[q[nodo].pos] = q[nodo].num;
    }
}

void sol(){
    int n;
    cin>>n;

    fore(i,2,n){
        int u;
        cin>>u;

        g[i].pb(u);
        g[u].pb(i);
    }

    fore(i,1,n){
        cin>>v[i];
    }

    dp.push_back(-1);
    dfs(1,0);

    fore(i,2,n){
        deb(res[i]);
    }

    debln("");
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