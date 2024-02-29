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

struct state {
    int len, link;
    map<char, int> next;
};

struct SAM {
    vector<state> st;
    vector<bool> vis;
    vector<ll> dp;
    int sz = 0, last;

    SAM (string s) {
        int n = s.size() * 2;
        st.resize(n);
        vis.resize(n);
        dp.resize(n);

        st[0].len = 0;
        st[0].link = -1;
        sz++;
        last = 0;

        for (auto x: s) {
            sa_extend(x);
        }
    }

    void sa_extend(char c) {
        int cur = sz++;
        st[cur].len = st[last].len + 1;
        dp[cur] = (cur == 0 ? 0 : 1);
        int p = last;
        while (p != -1 && !st[p].next.count(c)) {
            st[p].next[c] = cur;
            p = st[p].link;
        }
        if (p == -1) {
            st[cur].link = 0;
        } else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            } else {
                int clone = sz++;
                st[clone].len = st[p].len + 1;
                st[clone].next = st[q].next;
                st[clone].link = st[q].link;
                dp[clone] = 0;  // Para encontrar la cantidad de repetciones de un substrins
                while (p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }

    void diferentesSubStrings(int nodo, int padre) {
        // cerr << nodo << "\n";
        if (vis[nodo]) return;

        vis[nodo] = true;
        for (auto [c, pos]: st[nodo].next) {
            // cerr << c << " " << pos << "\n";
            // cerr << nodo << " " << pos << " " << c << "\n";
            diferentesSubStrings(pos, nodo);
            dp[nodo] += (dp[pos] + 1);
        }
    }

    void numerOfOcurrences() {
        vector<int> order(sz);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [this](int a, int b) {
            return st[a].len > st[b].len;
        });

        for (int v : order) {
            if (st[v].link != -1) {
                dp[st[v].link] += dp[v];
            }
        }
    }

    int masLago() {
        int res = 1;

        ll mx = *max_element(dp.begin() + 1, dp.end());
        int mxl = 1;
        set<int> estados;
        for (int i = 1; i < sz; i++) {
            if (dp[i] == mx) {
                if (st[mxl].len < st[i].len) {
                    mxl = i;
                    estados.clear();
                    estados.insert(i);
                }
                else if (st[mxl].len == st[i].len) {
                    estados.insert(i);
                }
            }
        }

        for (auto x: estados) {
            cout << x << " ";
        }
        cout << "\n";

        return res;
    }

    int encuentra_patron(string s) {
        int estado_actual = 0; // Empieza en el estado inicial
        for (char c : s) {
            if (st[estado_actual].next.count(c)) {
                // Si existe una transición para el carácter actual, sigue esa transición
                estado_actual = st[estado_actual].next[c];
            } 
            else {
                // Si no existe tal transición, la subcadena no está representada en el SAM
                return -1; // Puedes devolver -1 o cualquier otro indicador de "no encontrado"
            }
        }
        return estado_actual;
    }
};


void sol() {
    int n;
    string s;
    cin >> n >> s;

    SAM sa(s);
    sa.numerOfOcurrences();
    sa.masLago();

    for (auto x: sa.dp) {
        cerr << x << " ";
    }
    cout << sa.encuentra_patron("b") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    // cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}