#include<bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            sum += x;
        }
    }

    cout << fixed << setprecision(10) << 1.0 * sum / (n * m) << "\n";

    return 0;
}