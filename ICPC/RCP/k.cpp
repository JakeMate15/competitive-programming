#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int cnt = 0;
    vector<int> vis(n + 1);
    for (int i = 1; !vis[i]; i = arr[i]) {
        cnt++;
        vis[i] = 1;
    }

    cout << cnt << "\n";

    return 0;
}