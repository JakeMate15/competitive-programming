#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void sol () {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cnt = 0, dinero = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= k) {
            dinero += a[i];
        } else if (a[i] == 0 && dinero) {
            cnt++;
            dinero--;
        }
    }

    cout << cnt << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}