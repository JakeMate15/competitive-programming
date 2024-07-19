#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()

typedef long long ll;
typedef pair<int, int> ii;

void sol () {
    int n;
    cin >> n;

    vector<int> arr(n * 2);
    vector<vector<int>> g(n + 1, vector<int>());
    for (int i = 0; i < 2 * n; i++) {
        cin >> arr[i];
        g[arr[i]].push_back(i + 1);
    }

    ll res = 0;
    int a = 1, b = 1;
    for (int i = 1; i <= n; i++) {
        ll d1 = abs(a - g[i][0]) + abs(b - g[i][1]);
        ll d2 = abs(a - g[i][1]) + abs(b - g[i][0]);

        res += min(d1, d2);

        a = g[i][0];
        b = g[i][1];
    }

    cout << res << "\n";
    
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;

    while (t--) {
        sol();
    }

    return 0;
}