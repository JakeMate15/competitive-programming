#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void sol() {
    int n;
    cin >> n;

    vector<int> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    function<bool(int)> ok = [&] (int m) -> bool {
        vector<int> x(n);
        for (int i = 0; i < n; i++) {
            x[i] = m / k[i];
        }

        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += x[i];
        }

        for (int i = 0; i < n; i++) {
            if (sum / k[i] >= x[i])
                return false;
        }

        return true;
    };

    int lo = 49, hi = 1E9 + 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;

        if (ok(mid))
            hi = mid;
        else
            lo = mid;
    }

    if (hi == 1E9 + 1) {
        cout << -1 << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << hi / k[i] << " \n"[i == n - 1];
    }
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