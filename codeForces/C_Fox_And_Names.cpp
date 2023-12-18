#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

vector<vector<int>> g(26);
vector<char> color;
vector<int> parent;
int cycle_start, cycle_end, n = 26;

bool dfs(int v) {
    color[v] = 1;
    for (int u : g[v]) {
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u))
                return true;
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

bool ciclo() {
    color.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++) {
        if (color[v] == 0 && dfs(v))
            break;
    }

    if (cycle_start == -1) {
        // cout << "Acyclic" << endl;
        return false;
    } 
    else {
        return true;
    }
}

vector<bool> visited;
vector<int> ans;

void dfs2(int v) {
    visited[v] = true;
    for (int u : g[v]) {
        if (!visited[u])
            dfs2(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs2(i);
    }
    reverse(ans.begin(), ans.end());
}

void sol(){
    int n;
    cin >> n;

    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];

        // cerr << a[i] << ":\n";
        for(int j = 0; j < i; j++) {
            // cerr << a[j] << "\n";
            int mn = -1;
            for(int k = 0; k < min(sz(a[i]), sz(a[j])); k++) {
                if(a[i][k] != a[j][k]) {
                    mn = k;
                    break;
                }
            }

            if(mn == -1) {
                if(sz(a[i]) < sz(a[j])) {
                    cout << "Impossible\n";
                    return;
                }
                continue;
            }

            g[a[j][mn] - 'a'].push_back(a[i][mn] - 'a');
        }
        // cerr << "\n\n";
    }

    if(ciclo()) {
        cout << "Impossible\n";
    }
    else {
        topological_sort();
        for(auto x: ans) {
            char c = 'a' + x;
            cout << c;
        }
        nl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}