#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> win;
int raiz;

void dfs (int nodo, int padre, int h) {
    bool hoja = true, tM = true, tB = true;

    for (auto u: g[nodo]) {
        if (padre == u) continue;

        hoja = false;
        dfs(u, nodo, h + 1);

        if (!hoja) {
            tM &= !win[u];
            tB &= win[u];
        }   
    }

    win[nodo] = (hoja && (h % 2 == 0));

    if (!hoja) {
        if ((h & 1 && !tM) || (h % 2 == 0 && tB)) {
            win[nodo] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t;
    cin >> n >> t;

    g = vector<vector<int>>(n + 1, vector<int>());
    win = vector<int>(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cin >> raiz;
    
    dfs(raiz, 0, 0);
    cout << (win[raiz] ? "Hermione" : "Ron") << "\n";

    return 0;
}