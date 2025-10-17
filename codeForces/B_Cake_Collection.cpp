#include<bits/stdc++.h>
using namespace std;

void sol () {
    int n, m; 
    cin >> n >> m;

    vector<int> a(n);
    for (auto &x : a) 
        cin >> x;
    
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    int k = min(n, m);
    int64_t ans = 0;
    for (int i = 0; i < k; i++) 
        ans += 1LL * a[i] * (m - i);
    cout << ans << "\n";
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