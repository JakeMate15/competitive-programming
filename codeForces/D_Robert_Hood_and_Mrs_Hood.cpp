#include<bits/stdc++.h>
using namespace std;

void sol () {
    int n, d, k;
    cin >> n >> d >> k;

    vector<int> arr(n + 3, 0);
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;

        l = max(1, l - d + 1);

        arr[l]++;
        arr[r + 1]--;
    }

    int h = 1, m = 1;
    for (int i = 1; i <= n - d + 1; i++) {
        arr[i] += arr[i - 1];

        if (arr[i] > arr[h]) {
            h = i;
        }
        if (arr[i] < arr[m]) {
            m = i;
        }
    }

    cout << h << " " << m << "\n";
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