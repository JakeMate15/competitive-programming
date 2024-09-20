#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct SegmentTree {
    int N;
    vector<ll> volume;
    vector<int> name;

    SegmentTree() {}

    void build(int n, vector<ll>& vol, vector<int>& names) {
        N = n;
        volume.resize(N << 1);
        name.resize(N << 1);
        for (int i = 0; i < N; ++i) {
            volume[N + i] = vol[i];
            name[N + i] = names[i];
        }
        for (int i = N - 1; i > 0; --i) {
            volume[i] = volume[i << 1] + volume[i << 1 | 1];
            if (volume[i << 1] > volume[i << 1 | 1]) {
                name[i] = name[i << 1];
            } else if (volume[i << 1] < volume[i << 1 | 1]) {
                name[i] = name[i << 1 | 1];
            } else {
                name[i] = min(name[i << 1], name[i << 1 | 1]);
            }
        }
    }

    void update(int i, ll val, int newName) {
        i += N;
        volume[i] = val;
        name[i] = newName;
        while (i >>= 1) {
            volume[i] = volume[i << 1] + volume[i << 1 | 1];
            if (volume[i << 1] > volume[i << 1 | 1]) {
                name[i] = name[i << 1];
            } else if (volume[i << 1] < volume[i << 1 | 1]) {
                name[i] = name[i << 1 | 1];
            } else {
                name[i] = min(name[i << 1], name[i << 1 | 1]);
            }
        }
    }

    pair<ll, int> query(int l, int r) {
        ll resVolLeft = 0, resVolRight = 0;
        int resNameLeft = -1, resNameRight = -1;
        for (l += N, r += N; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) {
                if (resVolLeft == 0 || volume[l] > resVolLeft) {
                    resVolLeft = volume[l];
                    resNameLeft = name[l];
                } else if (volume[l] == resVolLeft) {
                    resNameLeft = min(resNameLeft, name[l]);
                }
                l++;
            }
            if (!(r & 1)) {
                if (resVolRight == 0 || volume[r] > resVolRight) {
                    resVolRight = volume[r];
                    resNameRight = name[r];
                } else if (volume[r] == resVolRight) {
                    resNameRight = min(resNameRight, name[r]);
                }
                r--;
            }
        }
        if (resVolLeft > resVolRight) {
            return {resVolLeft, resNameLeft};
        } else if (resVolLeft < resVolRight) {
            return {resVolRight, resNameRight};
        } else {
            return {resVolLeft, min(resNameLeft, resNameRight)};
        }
    }

    pair<ll, int> queryRoot() {
        return {volume[1], name[1]};
    }
};

struct HLD {
    int n;
    vector<int> siz, top, dep, parent, in, out, seq;
    vector<vector<int>> adj;
    vector<ll> volume;
    vector<int> name;
    SegmentTree st;
    int cur;

    HLD() {}
    HLD(int n) {
        init(n);
    }
    void init(int n) {
        this->n = n;
        siz.resize(n);
        top.resize(n);
        dep.resize(n);
        parent.resize(n);
        in.resize(n);
        out.resize(n);
        seq.resize(n);
        volume.resize(n);
        name.resize(n);
        cur = 0;
        adj.assign(n, {});
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void work(int root = 0) {
        top[root] = root;
        dep[root] = 0;
        parent[root] = -1;
        dfs1(root);
        dfs2(root);
        vector<ll> vol(n);
        vector<int> names(n);
        for (int i = 0; i < n; ++i) {
            vol[i] = volume[seq[i]];
            names[i] = name[seq[i]];
        }
        st.build(n, vol, names);
    }
    void dfs1(int u) {
        if (parent[u] != -1) {
            adj[u].erase(find(adj[u].begin(), adj[u].end(), parent[u]));
        }
        siz[u] = 1;
        for (auto& v : adj[u]) {
            parent[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[adj[u][0]]) {
                swap(v, adj[u][0]);
            }
        }
    }
    void dfs2(int u) {
        in[u] = cur++;
        seq[in[u]] = u;
        for (auto v : adj[u]) {
            top[v] = v == adj[u][0] ? top[u] : v;
            dfs2(v);
        }
        out[u] = cur;
    }

    void update(int u, ll val) {
        st.update(in[u], val, name[u]);
        volume[u] = val;
        int v = parent[u];
        while (v != -1) {
            ll leftVol = 0, rightVol = 0;
            int leftName = -1, rightName = -1;
            if (!adj[v].empty()) {
                int leftChild = adj[v][0];
                leftVol = volume[leftChild];
                leftName = name[leftChild];
                if (adj[v].size() > 1) {
                    int rightChild = adj[v][1];
                    rightVol = volume[rightChild];
                    rightName = name[rightChild];
                }
            }
            ll newVol = leftVol + rightVol;
            int newName;
            if (leftVol > rightVol) {
                newName = leftName;
            } else if (leftVol < rightVol) {
                newName = rightName;
            } else {
                newName = min(leftName, rightName);
            }
            if (volume[v] == newVol && name[v] == newName) {
                break;
            }
            volume[v] = newVol;
            name[v] = newName;
            st.update(in[v], newVol, newName);
            u = v;
            v = parent[v];
        }
    }

    int queryRootName() {
        return st.queryRoot().second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int totalNodes = 2 * N - 1;
    HLD hld(totalNodes);

    vector<ll> initialVolume(totalNodes, 0);
    vector<int> initialName(totalNodes, -1);

    for (int i = 0; i < N; ++i) {
        cin >> initialVolume[i];
        initialName[i] = i;
        hld.volume[i] = initialVolume[i];
        hld.name[i] = initialName[i];
    }

    int nodeIdx = N;
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        int idx = nodeIdx++;
        hld.addEdge(idx, a);
        hld.addEdge(idx, b);

        hld.volume[idx] = hld.volume[a] + hld.volume[b];
        if (hld.volume[a] > hld.volume[b]) {
            hld.name[idx] = hld.name[a];
        } else if (hld.volume[a] < hld.volume[b]) {
            hld.name[idx] = hld.name[b];
        } else {
            hld.name[idx] = min(hld.name[a], hld.name[b]);
        }
    }

    int root = nodeIdx - 1;
    hld.work(root);

    int Q;
    cin >> Q;

    cout << hld.queryRootName() + 1 << "\n";
    while (Q--) {
        int ni;
        ll qi;
        cin >> ni >> qi;
        --ni;
        hld.volume[ni] += qi;
        hld.update(ni, hld.volume[ni]);
        cout << hld.queryRootName() + 1 << "\n";
    }
    return 0;
}
