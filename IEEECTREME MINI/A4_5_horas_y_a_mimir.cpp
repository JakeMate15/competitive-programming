#include<bits/stdc++.h>
using namespace std;

void sol() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<vector<int64_t>> sum(n + 1, vector<int64_t>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> sum[i][j];
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    auto get = [&](int r, int c, int h, int w) -> int64_t {
        return sum[r][c] - sum[r - h][c] - sum[r][c - w] + sum[r - h][c - w];
    };

    vector<int64_t> dpFila(n + 1, 0), dpCol(m + 1, 0);
    for (int i = 1; i <= n; i++) {
        dpFila[i] = max(dpFila[i], dpFila[i - 1]);
        for (int j = 1; j <= m; j++) {
            dpCol[j] = max(dpCol[j], dpCol[j - 1]);

            if (i >= x && j >= y) {
                int64_t s = get(i, j, x, y);
                dpFila[i] = max(dpFila[i], s);
                dpCol[j] = max(dpCol[j], s);
            }

            if (i >= y && j >= x) {
                int64_t s = get(i, j, y, x);
                dpFila[i] = max(dpFila[i], s);
                dpCol[j] = max(dpCol[j], s);
            }
        }
    }

    int64_t res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i >= x && j >= y) {
                int64_t s = get(i, j, x, y);
                res = max(res, s + max(dpFila[i - x], dpCol[j - y]));
            }

            if (i >= y && j >= x) {
                int64_t s = get(i, j, y, x);
                res = max(res, s + max(dpFila[i - y], dpCol[j - x]));
            }
        }
    }

    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;

    while (t--) {
        sol();
    }

    return 0;
}
