#include<bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif
 
#define sz(a)       (int) a.size()
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
 
const int MX = 2E5 + 5;
const int MOD = 1E9 + 7;

void sol() {
    int n, q;
    cin >> n >> q;

    vector<int> g(n - 1);
    for (auto &x: g) {
        cin >> x;
    }

    vector<int> p(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
        
    }

    set<int> st;
    auto update = [&] (int i) -> void {
        if (p[i] * 2 >= n || i < 1) {
            return;
        }

        int nodo = p[i];
        int h1 = nodo * 2;
        int h2 = nodo * 2 + 1;
        int d1 = pos[h1] - pos[nodo];
        int d2 = pos[h2] - pos[nodo];

        int h = int (log2(n + 1)) - int (log2(h1));
        int tam = (1 << h);

        vector<bool> ok = {false, false};
        auto check = [&] (int d) -> void {
            if (d == 1) {
                ok[0] = true;
            } else if (d == tam) {
                ok[1] = true;
            }
        };

        check(d1);
        check(d2);

        if (!ok[0] || !ok[1]) {
            st.insert(nodo);
        } else {
            st.erase(nodo);
        }
    };

    for (int i = 1; i <= n; i++) {
        update(i);
    }

    while (q--) {
        int u, v;
        cin >> u >> v;

        swap(pos[p[u]], pos[p[v]]);
        swap(p[u], p[v]);

        update(u);
        update(v);

        int p1 = pos[p[u] / 2];
        int p2 = pos[p[v] / 2];

        update(p1);
        update(p2);

        cout << ((!sz(st) && p[1] == 1) ? "YES" : "NO") << "\n";
    }
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