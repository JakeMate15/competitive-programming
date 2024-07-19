#include <bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()
#define sz(a)   (int) a.size()

typedef long long ll;
typedef pair<int, int> ii;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    map<int, priority_queue<ll>> g;
    for (int i = 0; i < n; i++) {
        ll u, v;
        cin >> u >> v;

        g[u].push(v);
    }

    // for (auto v: g) {
    //     for (auto y: v) {
    //         cerr << y << " ";
    //     }
    //     cerr << "\n";
    // }

    vector<ll> res(max(n + 5, m + 5));
    for (auto &[i, pq]: g) {
        ll sum = 0;
        int idx = 0;
        while (!pq.empty()) {
            sum += pq.top();
            if (sum <= 0)
                break;
            pq.pop();
            res[idx++] += sum;
        }
    }

    // for (auto v: g) {
    //     for (auto x: v) {
    //         cerr << x << " ";
    //     }
    //     cerr << "\n";
    // }
    // cerr << "\n\n";

    ll r = 0;
    for (auto x: res) {
        r = max(r, x);
        // cerr << v << " ";
    }
    cout << r << "\n";

    return 0;
}