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
    vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

void sol() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    
    vector<set<int>> adj1(n), adj2(n);
    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj1[u].insert(v);
        adj1[v].insert(u);
    }
    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj2[u].insert(v);
        adj2[v].insert(u);
    }
    
    auto hasEdge = [&](auto &adj, int x, int y) {
        return adj[x].count(y);
    };
    
    vector<pair<int, int>> ans;
    if (n == 3) {
        int mask1 = 0, mask2 = 0;
        mask1 |= hasEdge(adj1, 0, 1);
        mask1 |= hasEdge(adj1, 0, 2) << 1;
        mask1 |= hasEdge(adj1, 1, 2) << 2;
        mask2 |= hasEdge(adj2, 0, 1);
        mask2 |= hasEdge(adj2, 0, 2) << 1;
        mask2 |= hasEdge(adj2, 1, 2) << 2;
        if ((mask1 ^ mask2) == 7) {
            cout << "No\n";
            return;
        }
        for (int i = 0; i < 3; i++) {
            if (~mask1 & ~mask2 & (1 << i)) {
                int u, v;
                if (i == 0) {
                    u = 0, v = 1;
                } else if (i == 1) {
                    u = 0, v = 2;
                } else {
                    u = 1, v = 2;
                }
                ans.emplace_back(u, v);
                mask1 |= 1 << i;
                mask2 |= 1 << i;
            }
        }
        if (__builtin_popcount(mask1) == 1) {
            for (int i = 0; i < 3; i++) {
                if (~mask1 & (1 << i)) {
                    int u, v;
                    if (i == 0) {
                        u = 0, v = 1;
                    } else if (i == 1) {
                        u = 0, v = 2;
                    } else {
                        u = 1, v = 2;
                    }
                    ans.emplace_back(u, v);
                    break;
                }
            }
        }
    } else {
        DSU dsu(n);
        vector<int> deg(n);
        vector<set<int>> e(n);
        for (int x = 0; x < n; x++) {
            for (auto y : adj2[x]) {
                if (dsu.merge(x, y)) {
                    deg[x]++;
                    deg[y]++;
                    e[x].insert(y);
                    e[y].insert(x);
                }
            }
        }
        
        int r = find(deg.begin(), deg.end(), n - 1) - deg.begin();
        if (r < n) {
            bool ok = false;
            for (int x = 0; x < n; x++) {
                for (auto y : adj2[x]) {
                    if (x != r && y != r) {
                        e[x].erase(r);
                        e[r].erase(x);
                        e[x].insert(y);
                        e[y].insert(x);
                        ok = true;
                        break;
                    }
                }
                if (ok) {
                    break;
                }
            }
            if (!ok) {
                for (int x = 0; x < n; x++) {
                    for (auto y = 0; y < x; y++) {
                        if (x != r && y != r) {
                            e[x].erase(r);
                            e[r].erase(x);
                            e[x].insert(y);
                            e[y].insert(x);
                            ans.emplace_back(x, y);
                            if (hasEdge(adj1, x, y)) {
                                adj1[x].erase(y);
                                adj1[y].erase(x);
                            } else {
                                adj1[x].insert(y);
                                adj1[y].insert(x);
                            }
                            ok = true;
                            break;
                        }
                    }
                    if (ok) {
                        break;
                    }
                }
            }
        }
        
        queue<int> q;
        q.push(0);
        
        set<int> nvis;
        for (int i = 1; i < n; i++) {
            nvis.insert(i);
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            
            set<int> newnvis;
            for (auto y : nvis) {
                if (!hasEdge(e, x, y)) {
                    q.push(y);
                    if (!hasEdge(adj1, x, y)) {
                        ans.emplace_back(x, y);
                    }
                } else {
                    newnvis.insert(y);
                }
            }
            nvis = newnvis;
        }
        assert(nvis.empty());
    }
    
    cout << "Yes\n";
    cout << ans.size() << "\n";
    for (auto [x, y] : ans) {
        cout << x + 1 << " " << y + 1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t, g;
    cin >> t >> g;

    while(t--) {
        sol();
    }

    return 0;
}