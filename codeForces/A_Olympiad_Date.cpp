#include<bits/stdc++.h>
using namespace std;

void sol () {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    vector<int> cnt = {3, 1, 2, 1, 0, 1, 0, 0, 0, 0};
    for (int i = 0; i < n; i++) {
        cnt[a[i]] = max(0, cnt[a[i]] - 1);
        if (accumulate(cnt.begin(), cnt.end(), 0) == 0) {
            cout << i + 1 << "\n";
            return;
        }
    }

    cout << 0 << "\n";
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