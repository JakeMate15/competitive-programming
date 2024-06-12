#include<bits/stdc++.h>
using namespace std;

#define sz(a)   (int) a.size()
#define all(a)  a.begin(), a.end()

typedef long long ll;
typedef pair<int, int> pi;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    vector<pi> pos;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            pos.emplace_back(i, j);
        }
    }

    sort(all(pos), [&](auto x, auto y) {
        return a[x.first][x.second] < a[y.first][y.second];
    });

    vector<int> x(n * n, 0);
    vector<int> y(n * n, 0);
    int res = 0;

    for (auto [i, j]: pos) {
        int antX = x[i]; 
        int antY = y[j]; 

        y[j] = max(y[j], antX + 1); 
        x[i] = max(x[i], antY + 1); 
        
        res = max({res, x[i], y[j]});
    }

    // Python >>>>> c++
    cout << res << "\n";

    return 0;
}