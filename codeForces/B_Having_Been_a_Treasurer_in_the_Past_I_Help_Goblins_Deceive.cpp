#include<bits/stdc++.h>
using namespace std;

void sol () {
    int n;
    string s;
    cin >> n >> s;

    map<char, int> cnt;
    for (auto &x: s) {
        cnt[x]++;
    }

    cout << 1LL * (cnt['-'] + 1) / 2 * cnt['_'] * (cnt['-'] / 2) << "\n";
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