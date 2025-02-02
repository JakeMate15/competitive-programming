#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

#define sz(a)       (int) a.size()
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int MX = 2E5 + 5;
const int MOD = 1E9 + 7;

void sol () {
    int n, m, l;
    cin >> n >> m >> l;

    vector<ii> h(n), p(m);
    for (auto &[a, b]: h) {
        cin >> a >> b;
    }
    for (auto &[a, b]: p) {
        cin >> a >> b;
    }

    int i = 0;
    ll power = 1, ans = 0;
    priority_queue<int> pq;
    for (const auto &[l, r]: h) {
        while (p[i].first <= l && i < m) {
            pq.push(p[i].second);
            i++;
        }
        
        while (l - 1 + power <= r && sz(pq)) {
            power += pq.top();
            pq.pop();
            ans++;
        }

        if (l - 1 + power <= r) {
            cout << -1 << "\n";
            return;
        }
    }

    cout << ans << "\n";
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