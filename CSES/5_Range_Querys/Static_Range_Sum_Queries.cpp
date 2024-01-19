#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    while(q--) {
        int l, r;
        cin >> l >> r;

        cout << (a[r] - a[l - 1]) << "\n";
    }

    return 0;
}