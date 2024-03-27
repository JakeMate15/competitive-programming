#include<bits/stdc++.h>
using namespace std;

int get(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return x / i;
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            while (a[i] != b[i]) {
                res++;
                if (a[i] > b[i]) {
                    a[i] = get(a[i]);
                }
                else {
                    b[i] = get(b[i]);
                }
            }
        }

        cout << res << "\n";
    }

    return 0;
}