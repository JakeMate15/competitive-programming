#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()
#define sz(a)   (int)a.size()

typedef int64_t ll;

int bs (const vector<ll> &a, int n, int pos) {
    int lo = -1, hi = n + 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;

        if (a[mid] <= pos) 
            lo = mid;
        else
            hi = mid;
    }

    return min(max(0, lo), n - 1);
}

void sol() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<ll> a(k + 2, 0), b(k + 2, 0);
    for (int i = 1; i <= k; i++)
        cin >> a[i];
    for (int i = 1; i <= k; i++)
        cin >> b[i];

    while (q--) {
        int pos;
        cin >> pos;

        int donde = bs(a, k + 1, pos);

        ll res = b[donde] + (pos - a[donde]) * (b[donde + 1] - b[donde]) / (a[donde + 1] - a[donde]);
        if (a[donde] == pos) {
            res = b[donde];
        }

        cout << res << " ";
    }
    cout << "\n";
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
