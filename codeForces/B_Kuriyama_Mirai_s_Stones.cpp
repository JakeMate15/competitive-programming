#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int64_t> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b.begin(), b.end());

    for (int i = 2; i <= n; i++) {
        a[i] += a[i - 1];
        b[i] += b[i - 1];
    }

    int q;
    cin >> q;
    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        cout << (op == 1 ? a[r] - a[l - 1] : b[r] - b[l - 1]) << "\n";
    }

    return 0;
}