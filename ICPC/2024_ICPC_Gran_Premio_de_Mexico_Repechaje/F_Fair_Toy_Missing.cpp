#include<bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int res = 0;
    vector<int> a(5), b(4);
    for (auto &x: a) {
        cin >> x;
        res += x;
    }
    for (auto &x: b) {
        cin >> x;
        res -= x;
    }

    cout << res << "\n";

    return 0;
}
