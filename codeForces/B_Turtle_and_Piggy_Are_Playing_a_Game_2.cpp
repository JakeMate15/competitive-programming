#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()

void sol() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &x: arr) {
        cin >> x;
    }

    sort(all(arr));

    cout << arr[n / 2] << "\n";
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