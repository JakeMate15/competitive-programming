#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = stoi(s);

    int res = 0;
    for (auto x: s) {
        int d = x - '0';
        if (d == 0) continue;
        res += (n % d == 0);
    }

    cout << res << "\n";
}