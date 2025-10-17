#include<bits/stdc++.h>
using namespace std;

const int64_t MX = 1E18;
const int MOD = 1E9 + 7;

void sol () {
    int n;
    cin >> n;

    vector<int> arr(2 * n);
    for (auto &x: arr) {
        cin >> x;
    }

    sort(arr.begin(), arr.end());

    int64_t s1 = 0, s2 = 0;
    vector<int> a1(arr.begin(), arr.begin() + n), a2(arr.begin() + n, arr.end());
    for (auto &x: a1) {
        s1 += x;
    }
    for (auto &x: a2) {
        s2 += x;
    }

    auto ok = [&] (int64_t x) -> bool {
        if (x < 1 || x > MX)
            return false;
        if (binary_search(a1.begin(), a1.end(), x) || binary_search(a2.begin(), a2.end(), x))
            return false;
        return true;
    };

    auto imp = [&] (int64_t a0) -> void {
        cout << a0 << " ";
        for (int i = 0; i < n; i++) 
            cout << a2[i] << " " << a1[i] << " ";
        cout << "\n";
    };

    int64_t dif = s2 - s1;
    if (ok(dif)) {
        imp(dif);
        return;
    }

    for (int i = 0; i < n; i++) {
        s1 -= a1[i];

        int64_t x = s2 - s1 - a1[i], a0 = a1[i];
        if (ok(x)) {
            a1[i] = x;
            imp(a0);
            return;
        }

        s1 += a1[i];
    }

    for (int i = 0; i < n; i++) {
        s2 -= a2[i];

        int64_t x = a2[i] + s1 - s2, a0 = a2[i];
        if (ok(x)) {
            a2[i] = x;
            imp(a0);
            return;
        }

        s2 += a2[i];
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