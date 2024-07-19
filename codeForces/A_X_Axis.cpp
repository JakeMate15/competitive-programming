#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        vector<int> a(3);
        for (auto &x: a)
            cin >> x;

        sort(a.begin(), a.end());

        int res = 0;
        for (int i = 0; i < 2; i++) {
            res += (a[i + 1] - a[i]);
        }

        cout << res << "\n";
    }

    return 0;
}