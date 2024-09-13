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

void sol () {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> g(n, vector<char>(m));
    int x1 = 2E5 + 5, x2 = 0, y1 = 2E5 + 5, y2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == '#') {
                x1 = min(x1, i);
                x2 = max(x2, i);
                y1 = min(y1, j);
                y2 = max(y2, j);
            }
        }
    }

    cout << (x1 + x2) / 2 + 1 << " " << (y1 + y2) / 2 + 1 << "\n";
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