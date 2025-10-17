#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    map<char, int> cnt;
    for (auto &x: s) {
        cnt[x]++;
    }

    bool par = true, imp = true;
    for (auto &[v, r]: cnt) {
        par &= r % 2 == 0;
        imp &= r & 1;
    }

    if (par) {
        cout << 0;
    } else if (imp) {
        cout << 1;
    } else {
        cout << "0/1";
    }

    return 0;
}