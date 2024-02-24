#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int n, m, m2;
vector<vector<char>> g;

int T;
vector<int> mt;
vector<int> used;

bool try_kuhn(int v){
    if (used[v] == T)
        return false;
    used[v] = T;
    forn(u, m2) if (g[v][u] && (mt[u] == -1 || try_kuhn(mt[u]))){
        mt[u] = v;
        return true;
    }
    return false;
}

int main() {
    cin >> n >> m;
    vector<string> b(m, string(n, '0'));
    forn(i, n){
        string t;
        cin >> t;
        forn(j, m) b[j][i] = t[j];
    }
    
    vector<string> nw = b;
    sort(nw.begin(), nw.end());
    nw.resize(unique(nw.begin(), nw.end()) - nw.begin());
    m2 = nw.size();
    g.assign(m2, vector<char>(m2, 0));
    forn(i, m2) forn(j, m2) if (i != j){
        bool in = true;
        forn(k, n) in &= nw[i][k] >= nw[j][k];
        if (in) g[i][j] = 1;
    }
    
    mt.assign(m2, -1);
    used.assign(m2, -1);
    T = 0;
    int k = m2;
    forn(i, m2) if (try_kuhn(i)){
        ++T;
        --k;
    }
    
    vector<int> nxt(m2, -1);
    vector<char> st(m2, true);
    forn(i, m2) if (mt[i] != -1){
        nxt[mt[i]] = i;
        st[i] = false;
    }
    
    vector<int> gr(m2), req(m2);
    int t = 0;
    forn(i, m2) if (st[i]){
        int v = i;
        int pos = 2;
        while (v != -1){
            gr[v] = t;
            req[v] = pos;
            ++pos;
            v = nxt[v];
        }
        ++t;
    }
    assert(t == k);
    
    vector<int> num(m);
    forn(i, m) num[i] = lower_bound(nw.begin(), nw.end(), b[i]) - nw.begin();
    
    printf("%d\n", k);
    forn(i, m) printf("%d ", gr[num[i]] + 1);
    puts("");
    forn(i, m) printf("%d ", req[num[i]]);
    puts("");
    forn(i, n){
        vector<int> l(k, 1);
        forn(j, m2) if (nw[j][i] == '1')
            l[gr[j]] = max(l[gr[j]], req[j]);
        forn(j, k)
            printf("%d ", l[j]);
        puts("");
    }
    return 0;
}