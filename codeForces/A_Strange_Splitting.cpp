#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void sol() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    if (a[0] == a[n - 1]) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    string s(n, 'R');
    s[1] = 'B';
    cout << s << "\n";
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