#include<bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;

    vector<string> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    int res = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cnt = 0;
            if (a[i][j] == 'N') {
                while (a[i][j] == 'N' && j < n) {
                    cnt++;
                    j++;
                }

                res += (cnt / 2);
                // cerr << cnt << "\n";
            }
        }
    }

    cout << res << "\n";
}