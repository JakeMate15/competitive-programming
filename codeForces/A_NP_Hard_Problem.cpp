#include<bits/stdc++.h>
using namespace std;
 
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl              cout << "\n";
typedef long long ll;

int isBipartiteDFS(int current, vector<vector<int>> &graph, vector<int> &color){
	bool is = 1;
	for(int child : graph[current]){
		if(color[child] == 0){//no esta coloreado
			color[child] = color[current] == 1 ? 2 : 1;// coloreo con el color opuesto a mi nodo current
			is = is & isBipartiteDFS(child, graph, color);
		}
		else if(color[child] == color[current]) return 0;//si son iguales no es bipartito 
	}
	return is;
}

void sol(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> color(n + 1);

    if(isBipartiteDFS(1, adj, color) == 0) {
        debln(-1);
        return;
    }

    for(auto x: color) {
        deb(x);
    }
    nl;

    vector<int> g1, g2;
    for(int i = 1; i <= n; i++) {
        if(color[i] == 1) {
            g1.push_back(i);
        }
        else if(color[i] == 0){
            g2.push_back(i);
        }
    }

    debln(sz(g1));
    for(auto x: g1) {
        deb(x);
    }
    nl;

    debln(sz(g2));
    for(auto x: g2) {
        deb(x);
    }
    nl;
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