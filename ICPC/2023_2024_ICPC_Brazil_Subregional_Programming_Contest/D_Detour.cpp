#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl              cout << "\n";
#define u_map           gp_hash_table
#define uid(a, b)       uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multi_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

void sol(){
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t=1;
    //cin>>t;

    while(t--){
        sol();
    }

    return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef pair<int, int> pii;

const int N = 305;

int n, m, d[N][2], vis[N][2], ans[N][N], adj[N][N];
vector<pii> edges;
bool h[N][2];

void dijk(int p){
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < 2; j++){
            d[i][j] = 1e9;
            vis[i][j] = h[i][j] = 0;
        }
    for(int i = 1; i <= n; i++)
        if(adj[p][i]){
            d[i][0] = adj[p][i];
            vis[i][0] = i;
        }
    h[p][0] = h[p][1] = true;
    while(true){
        int dist = 1e9, u, v;
        for(int j = 1; j <= n; j++)
            for(int k = 0; k < 2; k++)
                if(!h[j][k] && dist > d[j][k]){
                    dist = d[j][k];
                    u = j;
                    v = k;
                }
        if(dist == 1e9)
            break;
        h[u][v] = true;
        for(int j = 1; j <= n; j++){
            if(adj[u][j]){
                if(dist + adj[u][j] < d[j][0]){
                    if(vis[j][0] == vis[u][v])
                        d[j][0] = dist + adj[u][j];
                    else{
                        d[j][1] = d[j][0];
                        vis[j][1] = vis[j][0];
                        d[j][0] = dist + adj[u][j];
                        vis[j][0] = vis[u][v];
                    }
                }
                else if(dist + adj[u][j] < d[j][1] && vis[j][0] != vis[u][v]){
                    d[j][1] = dist + adj[u][j];
                    vis[j][1] = vis[u][v];
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(vis[i][0] != i)
            ans[p][i] = d[i][0];
        else if(vis[i][1])
            ans[p][i] = d[i][1];
        else
            ans[p][i] = -1;
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++){
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        adj[u][v] = c;
        adj[v][u] = c;
        edges.push_back({u, v});
    }
    for(int i = 1; i <= n; i++)
        dijk(i);
    for(pii i : edges)
        printf("%d\n", ans[i.st][i.nd]);
    return 0;
}

*/