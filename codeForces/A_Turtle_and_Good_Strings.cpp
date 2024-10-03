#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()

void sol() {
    int n;
    string s;
    cin >> n >> s;

    cout << (s[0] != s[n - 1] ? "YES" : "NO") << "\n";
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