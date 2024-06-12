#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multi_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

struct DSU {
    vector<int> par;
    vector<int> rank; // rank[x] = size of the component where x belongs
    int tam;
 
    DSU(int n) {
        par.resize(n + 1);
        rank.resize(n + 1);
        tam = n;
        for (int i = 1; i <= n; i++) {
            par[i] = i;
            rank[i] = 1;
        }
    }
 
    int find(int x) {
        if (par[x] == x) {
            return x;
        } 
        else {
            return (par[x] = find(par[x])); // Path Compression
        }
    }
 
    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty) {
            // both elements are in the same component
            return;
        }
        if (rank[rootx] < rank[rooty]) { // Rank Compression
            swap(rootx, rooty);
        }
        rank[rootx] += rank[rooty];
        par[rooty] = rootx;
        tam--;
    }

    bool same(int u, int v){
        return find(u) == find(v);
    }
};

void sol() {
    int n, m;
    cin >> n >> m;

    vvi pClausulas(m + 5), pVarialbes(n + 5);

    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        pClausulas[i].push_back(a);
        pClausulas[i].push_back(b);
        pClausulas[i].push_back(c);

        pVarialbes[a].push_back(i);
        pVarialbes[b].push_back(i);
        pVarialbes[c].push_back(i);
    }   

    if (m & 1) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            cout << 1 << " \n"[i == n - 1];
        }
        return;
    }

    // cerr << "====================\n";

    // for (auto x: pVarialbes) {
    //     for (auto y: x) {
    //         cerr << y << " ";
    //     }
    //     cerr << "\n";
    // }

    DSU ds(m + 5);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < sz(pVarialbes[i]); j++) {
            // cerr << pVarialbes[i][j - 1] << " " << pVarialbes[i][j] << "\n";
            ds.unite(pVarialbes[i][j - 1], pVarialbes[i][j]);
        }
    }

    for (int i = 1; i <= m; i++) {
        // cerr << ds.rank[ds.find(i)] << "\n";

        int tam = ds.rank[ds.find(i)];
        if ((tam) & 1 || (m - tam) & 1) {
            cout << "YES\n";
            
            vector<int> res(n + 1, 0);
            for (int i = 1; i <= n; i++) {
                cout << res[i] << " \n"[i == n];
            }

            return;
        }
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}


/*

Detalla  el  funcionamiento  del  clasificador  por  el  método  del  vecino más cercano K-NN (mínimo 1 cuartilla).

Investiga una aplicación reciente para este tipo de clasificador (mínimo media cuartilla) 

Ventajas y desventajas del clasificador por el método del vecino más cercano K-NN (mínimo 1 cuartilla). 






Descripción del conjunto de datos:
El conjunto de datos sintético generado consta de 200 registros, cada uno con 6 características numéricas. Estas características varían en un rango de 0 a 100 y están diseñadas para simular diferentes tipos de datos sensoriales o de medición que podrían encontrarse en aplicaciones reales. Las etiquetas de los datos están divididas en 4 clases distintas: Clase A, Clase B, Clase C y Clase D. Este conjunto de datos está diseñado para entrenar un modelo clasificador usando el algoritmo k-nearest neighbors (KNN), el cual intentará predecir la clase de un nuevo registro basado en la similitud de sus características con las de los registros del conjunto de entrenamiento.

Tarea del clasificador:
La tarea del clasificador KNN con este conjunto de datos será predecir correctamente la clase de nuevos objetos o registros basándose en sus características. Al introducir un nuevo objeto con sus respectivas características al modelo, el clasificador KNN buscará los k vecinos más cercanos entre los registros del conjunto de entrenamiento, y la clase predominante entre estos vecinos será asignada al nuevo objeto. Este método es particularmente útil para tareas de clasificación donde las relaciones entre las características y las clases pueden ser intuitivamente capturadas por la distancia entre los ejemplos.






*/