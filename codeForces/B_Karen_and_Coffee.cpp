#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, q;
    cin >> n >> k >> q;

    int MX = 200005;
    int l, r, a[MX], b[MX];
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        a[l]++;
        a[r + 1]--;
    }

    for (int i = 1; i < MX; i++) {
        a[i] += a[i - 1];
        b[i] = a[i] >= k;
        b[i] += b[i - 1];
    }

    while (q--) {
        cin >> l >> r;
        cout << b[r] - b[l - 1] << "\n";
    }

    return 0;
}