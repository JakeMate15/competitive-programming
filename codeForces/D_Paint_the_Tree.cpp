#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multi_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define all(v)          v.begin(), v.end()
#define rall(v)         v.rbegin(), v.rend()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

vvi g;
vi recorrido, ok, prof;
int res, a, b, cnt, n;
bool encontrados;
vector<ii> movimientos;

void dfs (int nodo, int padre) {
    recorrido.push_back(nodo);
    encontrados |= (nodo == b);

    for (auto u: g[nodo]) {
        if (u != padre && !encontrados) {
            dfs(u, nodo);
        }
    }

    if (!encontrados)
        recorrido.pop_back();
}

int profundiades (int nodo, int padre) {
    int profundidad = 0;
    for (int vecino : g[nodo]) {
        if (vecino != padre) {
            profundidad = max(profundidad, profundiades(vecino, nodo) + 1);
        }
    }
    prof[nodo] = profundidad;
    return profundidad;
}

void sol() {
    cin >> n;

    recorrido.clear();
    g = vvi(n + 1, vi());
    encontrados = false;
    ok = vi(n + 1);
    prof = vi(n + 1);
    movimientos.clear();

    cin >> a >> b;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(a, 0);

    int no, pa;
    if (sz(recorrido) & 1) {
        pa = 0;
        no = recorrido[sz(recorrido) / 2];

        cnt = 1;
        ok[pa] = 1;
        res = sz(recorrido) / 2;
    }
    else {
        int nc = sz(recorrido) / 2;
        no = recorrido[nc];
        pa = recorrido[nc - 1];

        cnt = 2;
        ok[pa] = ok[0] = 1;
        res = nc;
    }  

    prof[0] = -1;
    profundiades(no, 0);
    // res++;

    cout << n * 2 - res - 1 << "\n";
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

// -Wall -Wextra -Wshadow -D_GLIBCXX_ASSERTIONS -DDEBUG -ggdb3 -fmax-errors=2