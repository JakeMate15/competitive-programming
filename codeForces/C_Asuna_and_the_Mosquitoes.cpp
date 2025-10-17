#include<bits/stdc++.h>
using namespace std;

#define sz(a)       (int) a.size()
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()

const int MX = 2E5 + 5;
const int MOD = 1E9 + 7;

void sol () {
    int n; 
    cin >> n;

    int imp = 0;
    vector<int> a(n);
    int64_t sum = 0, mx = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        mx = max(mx, int64_t(a[i]));
        if(a[i] & 1) {
            imp++;
        }
    }

    if(n == 1 || imp == 0 || imp == n)
        cout << mx << "\n";
    else
        cout << sum - (imp - 1) << "\n";
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