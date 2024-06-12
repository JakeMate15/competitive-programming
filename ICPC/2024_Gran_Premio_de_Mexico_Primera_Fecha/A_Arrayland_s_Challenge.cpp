#include<bits/stdc++.h>
using namespace std;

const int MX = 1e4 + 5, inf = INT_MAX;

int arr[MX];
int dp[MX][MX], ok[MX][MX];

int go (int l, int r) {
    if (l + 1 == r) 
        return abs(arr[l] - arr[r]);

    int &mem = dp[l][r];
    int &vis = ok[l][r];

    if (vis)
        return mem;

    vis = 1;

    return mem = min({
        abs(arr[l] - arr[r]),
        go (l + 1, r),
        go (l, r - 1)
    });
}


int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;

        l--, r--;
        cout << go (l, r) << "\n";
    }

    return 0;
}