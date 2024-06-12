#include<bits/stdc++.h>
using namespace std;

const int MX = 1e5 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q, n;
    cin >> q >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    set<int> st = {0};
    for (int i = 1; i < MX; i++) {
        for (int j = 0; j < n; j++) {
            if (i - a[j] >= 0 && st.count(i - a[j]) > 0) {
                st.insert(i);
            }
        }
    }

    // for (auto x: st) {
    //     cerr << x << "\n";
    // }

    while (q--) {
        int x;
        cin >> x;

        cout << abs(x - *st.lower_bound(x)) << "\n";
    }

    return 0;
}