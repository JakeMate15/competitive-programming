#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> arr(n);
    for (auto &x: arr) {
        cin >> x;
    }

    long long res = arr[0], sum = 0;
    for (int i = 0; i < n; i++) {
        sum = max(sum + arr[i], arr[i]);
        res = max(res, sum);
    }

    cout << res << "\n";

    return 0;
}