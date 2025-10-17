#include<bits/stdc++.h>
using namespace std;

void sol () {
    int n, m; 
    cin >> n >> m;

    vector<long long> a(n);
    for (auto &x : a) 
        cin >> x;
    
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    long long k = min<long long>(n, m), ans = 0;
    for (long long i = 0; i < k; ++i) ans += a[i] * (m - i);
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