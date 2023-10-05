#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl()            cout << "\n"
typedef long long ll;

vector<vector<int>> arbol;
vector<int> hojas;
vector<bool> esHoja;

void dfs(int nodo, int padre) {

    for(auto u: arbol[nodo]) {
        if(u == padre) {
            if(sz(arbol[nodo]) == 1) {
                hojas[nodo] = 1;
                esHoja[nodo] = true;
            }
        }
        else{
            dfs(u, nodo);
        }
    }
}

void dfs2(int nodo, int padre) {

    for(auto u: arbol[nodo]) {
        if(u != padre) {
            dfs2(u, nodo);
            if(esHoja[u]) {
                hojas[nodo] += hojas[u];
            }
        }   
    }

}

void sol(){
    int n;
    cin >> n;

    arbol.clear(); arbol.resize(n + 1);
    hojas.clear(); hojas.resize(n + 1, 0);
    esHoja.clear(); esHoja.resize(n + 1, 0);
    
    for(int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        arbol[i].push_back(u);
        arbol[u].push_back(i);
    }

    dfs(1, 0);
    dfs2(1, 0);

    for(int i = 1; i <= n; i++) {
        if(!esHoja[i] && hojas[i] < 3) {
            debln("No");
            return;
        }
    }

    debln("Yes");

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