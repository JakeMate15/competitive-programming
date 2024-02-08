#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void sol() {
    int n;
    cin >> n;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    int res = n;

    for (int i = 1; i <= n; i++) {
        ll sum = a[i];
        int currTam = i, l = i + 1, r = i + 1;

        for (int j = i + 1; j <= n; j++) {
            if (a[j] - a[l - 1] == sum) {
                currTam = max(currTam, j - l + 1);
                l = j + 1;
            }
        }

        if (l == n + 1) {
            res = min(res, currTam);
        }
    }

    cout << res << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}