#include <bits/stdc++.h>
using namespace std;

int main () {
    int64_t n, k;
    cin >> n >> k;

    int64_t tam = 1, ans = 1, cnt = 0;
    while (tam * k + 1 < n && cnt < k) {
        tam = tam * k + 1;
        ans *= 2;
        cnt++;
    }

    cerr << tam << "\n";

    // if (n <= k) {
    //     cout << 0 << "\n";
    // } else {
    //     cout << n / (k) << "\n";
    // }

    // cerr << tam << "\n";

    return 0;
}