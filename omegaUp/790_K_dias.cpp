#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, x;
    cin >> n >> x >> k >> m;

    vector<vector<pair<int, int>>> graph(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF)); 

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    dp[1][0] = 0;
    for (int j = 1; j <= k; ++j) {
        for (int i = 1; i <= n; ++i) {
            for (auto &edge : graph[i]) {
                int u = edge.first;
                int w = edge.second;
                if (dp[i][j - 1] != INF) {
                    dp[u][j] = min(dp[u][j], dp[i][j - 1] + w);
                }
            }
        }
    }

    // Resultado
    if (dp[x][k] == INF) {
        cout << "No es posible alcanzar el nodo " << x << " con exactamente " << k << " aristas." << endl;
    } else {
        cout << dp[x][k] << "\n";
    }

    return 0;
}
