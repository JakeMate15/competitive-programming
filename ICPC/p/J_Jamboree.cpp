#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    
    sort(a.rbegin(), a.rend());

    if (n <= m) {
        cout << a[0] << "\n";
        return 0; 
    }

    while (a.size() < 2 * m) {
        a.push_back(0);
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        ans = max(ans, a[i] + a[2 * m - 1 - i]);
    }

    cout << ans << "\n";

    return 0;
}