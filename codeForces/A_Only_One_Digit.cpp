#include<bits/stdc++.h>
using namespace std;

void sol () {
    string s;
    cin >> s;

    cout << *min_element(s.begin(), s.end()) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}