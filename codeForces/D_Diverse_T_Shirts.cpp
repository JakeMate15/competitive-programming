#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> deg(n, 0);
    vector<vector<int>> A(n, vector<int>(n)), g(n);

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            A[i][j] = s[j] - '0';
            if (A[i][j] == 1) {
                g[i].push_back(j);
                deg[i]++;
            }
        }
    }

    vector<bool> s(n, false), rv(n, false);
    int rem = n, ans = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; ++i) {
        pq.push({deg[i], i});
    }

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (rv[u]) continue;

        s[u] = true;
        ans++;
        rv[u] = true;
        rem--;

        for (int v : g[u]) {
            if (!rv[v]) {
                rv[v] = true;
                rem--;
                for (int w : g[v]) {
                    if (!rv[w]) {
                        deg[w]--;
                        pq.push({deg[w], w});
                    }
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}