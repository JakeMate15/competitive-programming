#include<bits/stdc++.h>
using namespace std;

void sol() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &x: arr) {
        cin >> x;
    }

    int res = arr[0];
    for (int i = 0; i < n; i += 2) {
        res = max(res, arr[i]);
    }

    cout << res << "\n";
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