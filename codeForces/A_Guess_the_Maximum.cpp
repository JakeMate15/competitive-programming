#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void sol() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a)
        cin >> x;

    int res = INT_MAX;
    for (int i = 1; i < n; i++) {
        res = min(res, max(a[i], a[i - 1]) - 1);
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