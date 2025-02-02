#include<bits/stdc++.h>
using namespace std;

#define sz(a)       (int) a.size()
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int MX = 1E5;
const int MOD = 1E9 + 7;

int n;
int s[MX];
vector<int> adj[MX];
int ans = 0;

void dfs(int u, int p, vector<int> &curr) {
    int pos = lower_bound(all(curr), s[u]) - curr.begin();
    vector<int> rollBack = curr;
    if (pos == sz(curr)) {
        curr.push_back(s[u]);
    }
    else {
        curr[pos] = s[u];
    }
    ans = max(ans, sz(curr));
    for(auto &v : adj[u]) {
        if(v != p){
            dfs(v, u, curr);
        }
    }
    curr = rollBack;
}

void sol () {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n;i++) {
        vector<int> curr;
        dfs(i, 0, curr);
    }
    cout << ans;
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