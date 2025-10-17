#include<bits/stdc++.h>
using namespace std;

void sol () {
    int n;
    cin >> n;

    int s = 0;
    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
        s += x;
    }

    cout << s - n + 1 << "\n";
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