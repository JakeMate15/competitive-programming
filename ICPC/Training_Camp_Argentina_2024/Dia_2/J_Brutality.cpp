#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()

typedef long long ll;

void sol () {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    string s;
    cin >> s;

    ll res = 0;
    for (int i = 0; i < n; i++) {
        int j = i;

        priority_queue<ll> pq;
        while (s[j] == s[i] && j < n) {
            // cerr << s[j];
            pq.push(a[j]);
            j++;
        }

        int kk = k;
        while (kk-- && !pq.empty()) {
            res += pq.top();
            pq.pop();
        } 

        i = j - 1;
        // cerr << "\n";
    }

    cout << res << "\n";
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;

    while (t--) {
        sol();
    }

    return 0;
}