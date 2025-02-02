#include<bits/stdc++.h>
using namespace std;

void sol () {
    int n;
    cin >> n;

    vector<int64_t> pref(n + 2);
    vector<vector<int64_t>> mat(2, vector<int64_t>(n));
    for (auto &x: mat) {
        for (auto &y: x) {
            cin >> y;
        }
    }

    for (int i = 1; i <= n; i++) {
        pref[i] = max(mat[0][i - 1], mat[1][i - 1]);
        pref[i] += pref[i - 1];
    }

    int64_t ans = -1E18;
    for (int i = 1; i <= n; i++) {
        int64_t l = pref[i - 1];
        int64_t r = pref[n] - pref[i];
        int64_t m = mat[0][i - 1] + mat[1][i - 1];
        ans = max(ans, l + r + m);
    } 
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}