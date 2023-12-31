#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

vector<vector<pair<ll, int>>> g;

const int INF = 1e9;
vector<ll> dist;
vector<int> camino;
void dijkstra(int origen, int n) {
    dist.resize(n + 1, INF);
    camino.resize(n + 1, -1);

    dist[origen] = 0;
    //Dist, nodo
    set<pair<ll, int>> q = {{0LL, origen}};
    while(!q.empty()) {
        int nodo = q.begin() -> second;
        q.erase(q.begin());

        for(auto u: g[nodo]) {
            int v = q.begin() -> second;
            ll peso = q.begin() -> first;

            if(dist[v] > dist[nodo] + peso) {
                q.erase({dist[v], v});
                dist[v] = dist[nodo] + peso;
                camino[v] = nodo;
                q.insert({dist[v], v});
            }
        }
    }   
}

void sol(){
    int n, m;
    cin >> n >> m;

    
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