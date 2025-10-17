#include<bits/stdc++.h>
using namespace std;

#define all(a)      a.begin(), a.end()
#define cnt(a, b)   count(all(a), b)   

void sol () {
    int n, k;
    string s;
    cin >> n >> k >> s;

    int x = min(cnt(s, '0'), cnt(s, '1'));
    cout << (2 * (k + x) != n ? "NO" : "YES") << "\n";
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