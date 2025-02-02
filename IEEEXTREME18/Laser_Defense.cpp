#include<bits/stdc++.h>
using namespace std;

#define sz(a)       (int) a.size()
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int MX = 2E5 + 5;
const int MOD = 1E9 + 7;

void sol () {
    int l, n, m;
    cin >> l >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        char op;
        int x;
        cin >> op >> x;

        if (op == 'U') {
            a[i] = x;
        } else {
            a[i] = l;
        }
    }
    for (int i = 0; i < m; i++) {
        char op;
        int x;
        cin >> op >> x;

        if (op == 'U') {
            b[i] = x;
        } else {
            b[i] = 0;
        }
    }
    // 7 + 

    sort(all(a));
    sort(all(b));

    // for (auto x: a) {
    //     cerr << x << " ";
    // }
    // cerr << "\n";
    // for (auto x: b) {
    //     cerr << x << " ";
    // }
    // cerr << "\n";

    int64_t cnt = 1 + n + m;
    for (int i = 0; i < n; i++) {
        int it = lower_bound(all(b), a[i]) - b.begin();
        // cerr << it << "\n";
        cnt += it;
    }
    // for (int i = 0; i < m; i++) {
    //     int it = lower_bound(all(a), b[i]) - a.begin();
    //     cnt += it;
    // }

    cout << cnt << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    // cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}