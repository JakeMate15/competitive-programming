#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

vector<vector<int>> arbol;
vector<int>a, b, distInd;

void dfs(int u, int p, vector<int> &dist){
    for (auto v : arbol[u]) {
        if (v != p) {
            dist[v] = dist[u] + 1;
            dfs(v, u, dist);
        }
    }
}

void sol(){
    int n,m;
    cin>>n>>m;
    a.clear();
    arbol.clear();
    b.clear();
    distInd.clear();
    a.resize(n+1,0);
    b.resize(n+1,0);
    distInd.resize(n+1,0);
    arbol.resize(n+1);

    for(int i = 0; i < n - 1; i++){
        int u,v;cin>>u>>v;
        arbol[u].push_back(v);
        arbol[v].push_back(u);
    }

    dfs(1, 0, distInd);
    int n1 = max_element(all(distInd)) - distInd.begin();

    dfs(n1, 0, a);
    int n2 = max_element(all(a)) - a.begin();

    dfs(n2,0,b);
    
    map<int,int> nodos;
    for(int i = 1; i <= n; i++){
        int actual = max(a[i],b[i]);
        //cerr << actual << " ";
        if(nodos.count(actual)){
            nodos[actual]++;
        }
        else{
            nodos[actual] = 1;
        }
    }
    
    int x = nodos[3];
    int y = nodos[4] / x;

    cout << x << " " << y << endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t=1;
    cin>>t;

    while(t--){
        sol();
    }

    return 0;
}


