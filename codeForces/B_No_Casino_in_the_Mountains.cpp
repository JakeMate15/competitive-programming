#include<bits/stdc++.h>
using namespace std;

void sol () {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (auto &x: arr) {
        cin >> x;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!arr[i]) {
            int cnt = 0;
            while (i < n && !arr[i]) {
                i++, cnt++;
            }
            i--;
            ans += (cnt + 1) / (k + 1);
        }
    }

    cout << ans << "\n";
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