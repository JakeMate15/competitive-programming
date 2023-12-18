#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

const int mx = 1e5+5;
vector<int> g[mx];
int v[mx];

struct query{
    int op,num,pos;
};
vector<query> q(mx);
vector<int> dp;
int res[mx];

void dfs(int nodo, int padre){
    if(dp.back() < v[nodo]){
        dp.push_back(v[nodo]);
        q[nodo].op = 1;
    }
    else{
        int i = lower_bound(all(dp), v[nodo]) - dp.begin();
        q[nodo].op = 2, q[nodo].num = dp[i], q[nodo].pos = i;
        dp[i] = v[nodo];
    }

    res[nodo] = sz(dp) - 1;
    
    for(auto u: g[nodo]){
        if(u != padre){
            dfs(u,nodo);
        }
    }

    if(q[nodo].op == 1){
        dp.pop_back();
    }
    else if(q[nodo].op == 2){
        dp[q[nodo].pos] = q[nodo].num;
    }
}

void sol(){
    int n;
    cin>>n;

    for(int i = 2; i <= n; i++) {
        int u;
        cin >> u;

        g[i].push_back(u);
        g[u].push_back(i);
    }

    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    dp.push_back(-1);
    dfs(1,0);

    for(int i = 2; i <= n; i++) {
        cout << res[i] << " ";
    }

    nl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}