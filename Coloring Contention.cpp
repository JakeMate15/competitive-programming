#include <bits/stdc++.h>

using namespace std;

vector<int> grafo[100000+5];
bool vis[100000+5];
int dist[100000+5];
queue<int> q;

void sol(int origen){
    vis[origen] = true;
    dist[origen] = 0;
    q.push(origen);
    while (!q.empty()) {
        int s = q.front(); q.pop();
        // process node s
        for (auto u : grafo[s]) {
        if (vis[u]) continue;
        vis[u] = true;
        dist[u] = dist[s]+1;
        q.push(u);
        }
    }
}


int main (){
    int n,m;
    cin >> n >> m;
    int a,b;

    for(int i=0; i<m; i++){
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);

        vis[i+1] = false;
        dist[i+1] = 0;
    }


        sol(1);
        cout << dist[n]-1 << endl;
    

    //cout << endl << ciclos << endl;
    return 0;
}