#include<bits/stdc++.h>
using namespace std;

const int MX = 2E5 + 5;
const int MOD = 1E9 + 7;

void sol () {
    int n, k;
    cin >> n >> k;

    vector<int> ans;
    if (k & 1) {
        ans = vector<int>(n, n);
        ans[n - 1] = n - 1; 
    } else {
        ans = vector<int>(n, n - 1);
        ans[n - 2] = n;
    }
    for (auto &x: ans) 
        cout << x << " ";
    cout << "\n";
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