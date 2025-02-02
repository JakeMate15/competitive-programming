#include<bits/stdc++.h>
using namespace std;

void sol () {
    int ans = 0;
    vector<string> arr(12);
    for (int i = 0; i < 12; i++) {
        cin >> arr[i];
        ans += (arr[i].size() == i + 1);
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}